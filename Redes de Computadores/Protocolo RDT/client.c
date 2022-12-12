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

#define MAX_RES 1024

static struct header {
	int ack;
	int seqnum;
	int checksum;
	char data[MAX_RES];
} sendhdr, recvhdr;

int getChecksum(char *addr, int recvChecksum) {
	int count = strlen(addr);
	register long sum = recvChecksum;
	register long checksum;

	while (count > 1) {
		sum += *addr++;
		count -= 2;
	}
	if (count > 0) {
		sum += * (unsigned char *) addr;
	}
	while (sum >> 16) {
		sum = (sum & 0xffff) + (sum >> 16);
	}

	if (recvChecksum > 0) checksum = ~sum;
	else checksum = sum;

	return checksum;
}

void make_pkt(int seqnum, char *data, int checksum) {
	strcpy(sendhdr.data, data);
	sendhdr.seqnum = seqnum;
	sendhdr.checksum = checksum;
}

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

	int n, checksum, oncethru = 0;
	socklen_t addr_len = sizeof(struct sockaddr_in);
	char data[MAX_RES];

	int i = 0;
	while (1) {
		sleep(1);
		strcpy(sendhdr.data, "Solicitando pacote");
		sendto(sockfd, (void *)&sendhdr, sizeof(struct header), 0, (struct sockaddr *)&servaddr, sizeof(struct sockaddr_in));
		do {
			//if (i == 5) sleep(6);
			n = recvfrom(sockfd, (void *)&recvhdr, sizeof(struct header), 0, (struct sockaddr *)&servaddr, &addr_len);
			if (recvhdr.seqnum == (oncethru+1)%2) {
				sendto(sockfd, (void *)&sendhdr, sizeof(struct header), 0, (struct sockaddr *)&servaddr, sizeof(struct sockaddr_in));
			}

			//printf("checksumRecv: %d\n", getChecksum(recvhdr.data, recvhdr.checksum));

		} while ( n < 0 || recvhdr.seqnum == (oncethru+1)%2 );

		printf("Servidor IP(%s):Porta(%d): %d bytes: %s \n",
		inet_ntoa(servaddr.sin_addr),
		ntohs(servaddr.sin_port),
		n, recvhdr.data);

		//printf("Pacote %d recebido\n", oncethru);

		if (recvhdr.seqnum == 0) strcpy(data, "ACK0");
		else strcpy(data, "ACK1");

		checksum = getChecksum(data, 0);
		make_pkt(recvhdr.seqnum, data, checksum);
		sendto(sockfd, (void *)&sendhdr, sizeof(struct header), 0, (struct sockaddr *)&servaddr, sizeof(struct sockaddr_in));

		oncethru = (oncethru+1)%2;
		i++;
	}

	close(sockfd);
	return 0;
}

