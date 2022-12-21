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

  socklen_t addr_len;
  struct sockaddr_in caddr;
  addr_len = sizeof(struct sockaddr_in);

  int pck_recv = 0;
  while (pck_recv < PCK_NUM) {
    // Pacote esperado recebido //
    if ( (rdt_recv(s,  pck_recv, caddr)) ) {
        pck_recv++;
    }
  }

  close(s);
  return 0;
}

