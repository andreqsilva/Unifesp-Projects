#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/time.h>
#include <errno.h>
#include <string.h>

#define MAX_REQ 1024

struct packet_t {
  unsigned short ack;
  unsigned short seqnum;
  int checksum;
  unsigned char message[MAX_REQ];
};
typedef struct packet_t packet_t;

float time_diff(struct timeval *start, struct timeval *end){
    return (end->tv_sec - start->tv_sec) + 1e-9*(end->tv_usec - start->tv_usec);
}

struct timeval settimer(int rtt) {
  struct timeval timeout;
  timeout.tv_sec = rtt;
  timeout.tv_usec = 0;
  return timeout;
}

int isACK(int seqnum, int seq) {
  if (seqnum == seq) return 1;
  else return 0;
}

int getChecksum(unsigned char *addr, int msg_size) {
  int count = strlen(addr);
  register long sum = msg_size;
  register long checksum;

  while (count > 1) {
    sum += *addr++;
    count -= 2;
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

packet_t make_packet(unsigned char *msg, int msg_size, unsigned short seqnum) {
  packet_t pck;
  bzero(&pck, sizeof(packet_t));
  pck.ack = 0;
  pck.seqnum = seqnum;
  pck.checksum = getChecksum(msg, 0);
  memcpy(pck.message, msg, msg_size);
  return pck;
}

int seq_num = 0;

int rdt_send(int s, unsigned char *msg, int msg_size, struct sockaddr_in dst) {
  packet_t recvpck, sendpck = make_packet(msg, msg_size, seq_num);
  socklen_t addr_len = sizeof(struct sockaddr_in);
  struct timeval t1, t2;
  int nr, ns, nextseq = 0, rtt = 5;

  do {
    gettimeofday(&t1, NULL);
    ns = sendto(s, (void *)&sendpck, sizeof(packet_t), 0, (struct sockaddr *)&dst, sizeof(struct sockaddr_in));
    struct timeval timeout = settimer(rtt);
    if (setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
      perror("setsockopt()");
      return -1;
    }

    //printf("sendmessage=%s, seqnum=%d, checksum=%d\n", sendpck.message, sendpck.seqnum, sendpck.checksum);

    do {
      nr = recvfrom(s, (void *)&recvpck, sizeof(packet_t), 0, (struct sockaddr *)&dst, &addr_len);
      if (nr < 0) {
        if (errno == EWOULDBLOCK || errno == EAGAIN) {
          perror("socket timeout");
          break;
        }
      }
      if (!corrupt(recvpck.message, recvpck.checksum) && isACK(recvpck.seqnum, seq_num)) {
        nextseq = 1;
      }
    } while (!nextseq);

    printf("Receiver IP(%s): %d bytes: %s \n",
            inet_ntoa(dst.sin_addr),
            nr,
            recvpck.message);
    fflush(stdout);

  } while (!nextseq);

  gettimeofday(&t2, NULL);
  rtt = time_diff(&t1, &t2);
  seq_num = (seq_num+1) % 2;
  return 0;
}

int oncethru = 0;

int rdt_recv(int s, struct sockaddr_in rmt) {
  packet_t sendpck, recvpck;
  socklen_t addr_len = sizeof(struct sockaddr_in);
  unsigned char message[MAX_REQ];
  int nr, ns, msg_size, next = 0;
  do {
    do {
      nr = recvfrom(s, (void *)&recvpck, sizeof(packet_t), 0, (struct sockaddr *)&rmt, &addr_len);
      if (!corrupt(recvpck.message, recvpck.checksum) && recvpck.seqnum == oncethru) {
        next = 1;
      }
    } while (!next);

    printf("Sender IP(%s): %d bytes: %s\n",
  					inet_ntoa(rmt.sin_addr),
  					nr,
  					recvpck.message);
  	fflush(stdout);

    if (oncethru == 0) strcpy(message, "ACK0");
    else strcpy(message, "ACK1");
    msg_size = sizeof(message);

    sendpck = make_packet(message, msg_size, oncethru);
    ns = sendto(s, (void *)&sendpck, sizeof(packet_t), 0, (struct sockaddr *)&rmt, sizeof(struct sockaddr_in));
  } while (!next);
  oncethru = (oncethru+1) % 2;
  return 0;
}
