#include "rdt.h"
#include "rdt-protocol.c"

int main(int argc, char **argv) {

  if (argc != 3) {
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
  addr.sin_port = htons(atoi(argv[2]));
  addr.sin_family = AF_INET;

  if (inet_pton(AF_INET, argv[1], &addr.sin_addr) < 0) {
    perror("inet_pton()");
    return -1;
  }

  int msg_size, pck_send = 0;
  while (pck_send < PCK_NUM) {
    unsigned char message[MAX_REQ];
    sprintf(message, "packet(%d)", pck_send);
    msg_size = sizeof(message);
    rdt_send(s, message, msg_size, pck_send, addr);
    pck_send++;
  }

  close(s);
  return 0;
}

