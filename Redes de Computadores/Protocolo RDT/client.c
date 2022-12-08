#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <string.h>
#include <strings.h>
#include <sys/time.h>
#include <errno.h>

#define MAXLINE 1000

static struct hdr {
	uint32_t seq_num;
	char message[MAXLINE];
} sendhdr, recvhdr;

static struct msghdr msgsend, msgrecv;

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

	int n;
	char sendline[MAXLINE] = {"message from client"}, recvline[MAXLINE + 1];
	socklen_t addr_len = sizeof(struct sockaddr_in);
	struct timeval timeout;

	timeout.tv_sec = 5;  // segundos
	timeout.tv_usec = 0; // microssegundos

	if (setsockopt (sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
		perror("setsockop()");
	}

	sendhdr.seq_num = 10;
	sendto(sockfd, (void *)&sendhdr, sizeof(struct hdr), 0, (struct sockaddr *)&servaddr, sizeof(struct sockaddr_in));

	n = recvfrom(sockfd, (void *)&recvhdr, sizeof(struct hdr), 0, (struct sockaddr *)&servaddr, &addr_len);
	if (n < 0) {
		if (errno == EWOULDBLOCK) {
			perror("socket timeout");
			return -1;
		} else {
			perror("recvfrom()");
			return -1;
		}
	}

	printf("Servidor IP(%s):Porta(%d): %d bytes: %s\n",
		inet_ntoa(servaddr.sin_addr),
		ntohs(servaddr.sin_port),
		n, recvhdr.message);

	close(sockfd);
	return 0;
}
