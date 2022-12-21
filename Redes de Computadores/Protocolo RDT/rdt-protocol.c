#include "rdt.h"

struct packet_t {
  unsigned short ack;
  unsigned short seqnum;
  unsigned int checksum;
  unsigned char message[MAX_REQ];
};
typedef struct packet_t packet_t;

float time_diff(struct timeval *start, struct timeval *end){
    return ((end->tv_sec - start->tv_sec) * 1000) + (end->tv_usec - start->tv_usec) / 1000;
}

int isACK(int seqnum, int seq) {
  if (seqnum == seq) return 1;
  else return 0;
}

unsigned int getChecksum(unsigned char *addr, int msg_size) {
  int count = strlen(addr);
  register long sum = msg_size;
  register long checksum;

  while (count > 1) {
    sum += *addr++;
    count -= 1;
  }
  if (count > 0) {
    sum += *(unsigned char *) addr;
  }
  while (sum >> 16) {
    sum = (sum & 0xffff) + (sum >> 16);
  }
  checksum = ~sum;
  return checksum;
}

int corrupt(unsigned char *msg, int recvchecksum) {
  int checksum = getChecksum(msg, recvchecksum) * (-1);
  if (checksum == 65535) return 0; // mesmo checksum
  else return 1;
}

packet_t make_packet(unsigned char *msg, int msg_size, unsigned short seqnum, unsigned short ack) {
  packet_t pck;
  bzero(&pck, sizeof(packet_t));
  pck.ack = ack;
  pck.seqnum = seqnum;
  pck.checksum = getChecksum(msg, 0);
  memcpy(pck.message, msg, msg_size);
  return pck;
}

float desvio = 0;
float rtt_estimado = 20; // 20 ms
float msec = 20;

float get_timeout(float rtt_estimado, float rtt_amostrado) {
  float alpha = 0.125;
  rtt_estimado = ((1 - alpha) * rtt_estimado) + (alpha * rtt_amostrado);
  float beta = 0.25;
  desvio = ((1 - beta) * desvio) + (beta * abs(rtt_amostrado - rtt_estimado));
  return (rtt_estimado + (4 * desvio));
}

void settimer(int s, struct timeval timeout, float msec) {
  timeout.tv_sec = 0; // segundos
  timeout.tv_usec = msec * 1000; // microssegundos
  if (setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
    perror("setsockopt()");
  }
}

int seq_num = 0;

int rdt_send(int s, unsigned char *msg, int msg_size, int req, struct sockaddr_in dst) {
  packet_t recvpck, sendpck;
  socklen_t addr_len = sizeof(struct sockaddr_in);
  struct timeval timeout, t1, t2;
  int nr, ns;
  float rtt_amostrado;

  do {
    gettimeofday(&t1, NULL);
    sendpck = make_packet(msg, msg_size, seq_num, 1);
    ns = sendto(s, (void *)&sendpck, sizeof(packet_t), MSG_CONFIRM,
                (struct sockaddr *)&dst, sizeof(struct sockaddr_in));

    settimer(s, timeout, msec);
    nr = recvfrom(s, (void *)&recvpck, sizeof(packet_t), MSG_WAITALL,
                  (struct sockaddr *)&dst, &addr_len);
    if (nr < 0) {
      if (errno == EWOULDBLOCK || errno == EAGAIN) {
        perror("socket timeout");
        continue;
      }
    }
  } while (nr < 0 || corrupt(recvpck.message, recvpck.checksum) || !isACK(recvpck.seqnum, seq_num));

  gettimeofday(&t2, NULL);
  rtt_amostrado = time_diff(&t1, &t2);
  msec = get_timeout(rtt_estimado, rtt_amostrado);
  //printf("rtt_amostrado=%.3f, timeout=%.3f\n", rtt_amostrado, msec);
  printf("%d bytes from %s: req=%d rtt=%.3f ms: %s\n",
    nr,
    inet_ntoa(dst.sin_addr),
    req,
    rtt_amostrado,
    recvpck.message);
  fflush(stdout);

  seq_num = (seq_num+1) % 2;
  return 0;
}

int oncethru = 0;

int rdt_recv(int s, int req, struct sockaddr_in rmt) {
  packet_t recvpck, sendpck;
  socklen_t addr_len = sizeof(struct sockaddr_in);
  unsigned char message[MAX_REQ];
  struct timeval t1, t2;
  int nr, ns, msg_size;
  float rtt_amostrado;

  do {
    gettimeofday(&t1, NULL);
    nr = recvfrom(s, (void *)&recvpck, sizeof(packet_t), MSG_WAITALL,
                  (struct sockaddr *)&rmt, &addr_len);
  } while (nr < 0 || corrupt(recvpck.message, recvpck.checksum));

  if (recvpck.seqnum == 0) strcpy(message, "ACK0");
  else strcpy(message, "ACK1");

  msg_size = sizeof(message);
  sendpck = make_packet(message, msg_size, recvpck.seqnum, 1);
  //usleep(50 * 1000);
  ns = sendto(s, (void *)&sendpck, sizeof(packet_t), MSG_CONFIRM,
              (struct sockaddr *)&rmt, sizeof(struct sockaddr_in));
  gettimeofday(&t2, NULL);
  rtt_amostrado = time_diff(&t1, &t2);

  if (recvpck.seqnum == oncethru) {
    // Consome o pacote //
    printf("%d bytes from %s: req=%d rtt=%.3f ms: %s\n",
      nr,
      inet_ntoa(rmt.sin_addr),
      req,
      rtt_amostrado,
      recvpck.message);
    fflush(stdout);

    oncethru = (oncethru+1) % 2;
    return 1;
  }

  return 0;
}

