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

  unsigned char message[MAX_REQ] = {"packet"};
  int cfd, nr, msg_size = sizeof(message);
  socklen_t addr_len;

  while (1) {
    struct sockaddr_in caddr;
    addr_len = sizeof(struct sockaddr_in);
    if (cfd < 0) {
      perror("accept()");
      close(s);
      return -1;
    }
    cfd = s;
    unsigned char req[MAX_RES];
    nr = recvfrom(cfd, req, MAX_REQ, 0, (struct sockaddr *)&caddr, &addr_len);
    rdt_send(cfd, message, msg_size, caddr);
  }

  close(s);
  return 0;
}
