#include "rdt.h"
#include "rdt-protocol.c"

int main(int argc, char **argv) {

  if (argc != 2) {
    printf("%s <porta>\n", argv[0]);
    return 0;
  }

  int s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (s < 0) {
    perror("socket()");
    return -1;
  }

  struct sockaddr_in addr;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(atoi(argv[1]));
  addr.sin_family = AF_INET;

  if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind()");
    return -1;
  }


  int cfd, nr, pck_send, msg_size;
  socklen_t addr_len;

  struct sockaddr_in caddr;
  addr_len = sizeof(struct sockaddr_in);
  if (cfd < 0) {
    perror("accept()");
    close(s);
    return -1;
  }
  cfd = s;
  unsigned char req[MAX_RES];
  // Esperando requisição //
  nr = recvfrom(cfd, req, MAX_REQ, MSG_WAITALL, (struct sockaddr *)&caddr, &addr_len);
  pck_send = 0;
  // Enviando os pacotes //
  while (pck_send < PCK_NUM) {
    unsigned char message[MAX_REQ];
    sprintf(message, "packet(%d)", pck_send);
    msg_size = sizeof(message);
    rdt_send(cfd, message, msg_size, pck_send, caddr);
    pck_send++;
  }

  close(s);
  return 0;
}
