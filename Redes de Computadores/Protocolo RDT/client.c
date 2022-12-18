#include "rdt.h"
#include "rdt-protocol.c"

int main(int argc, char **argv) {
	int sockfd;
	struct sockaddr_in servaddr;

	if (argc != 2) {
		printf("%s <porta>\n", argv[1]);
		return 0;
	}

	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket()");
		return -1;
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[1]));

	if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) < 0) {
		perror("inet_pton()");
		return -1;
	}

	int ns;
	unsigned char reqmsg[MAX_RES] = {"Requisitando pacote"};
	packet_t recvpck;

  while (1) {
    sleep(1);
    ns = sendto(sockfd, reqmsg, MAX_RES, 0, (struct sockaddr *)&servaddr,
                sizeof(struct sockaddr_in));
    rdt_recv(sockfd, servaddr);
  }

	close(sockfd);
	return 0;
}
