#include "rdt.h"
#include "rdt-protocol.c"

int main(int argc, char **argv) {

  if (argc != 2) {
    printf("%s <porta>\n", argv[0]);
    return 0;
  }

  int s = socket(AF_INET, SOCK_DGRAM, 0);
  if (s < 0) {
    perror("socket()");
    return -1;
  }

  struct sockaddr_in addr;
  bzero(&addr, sizeof(addr));
  addr.sin_port = htons(atoi(argv[1]));
  addr.sin_family = AF_INET;

  if (inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr) < 0) {
    perror("inet_pton()");
    return -1;
  }

  int ns, pck_recv = 0;
  unsigned char reqmsg[MAX_RES] = {"Requisitando pacote"};

  // Enviando requisição //
  ns = sendto(s, reqmsg, MAX_RES, MSG_CONFIRM, (struct sockaddr *)&addr, sizeof(struct sockaddr_in));
  // Recebendo os pacotes //
  while (pck_recv < PCK_NUM) {
    rdt_recv(s, pck_recv, addr);
    pck_recv++;
  }

  close(s);
  return 0;
}
