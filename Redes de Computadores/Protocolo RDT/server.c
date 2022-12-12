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

#define FILA 1000
#define MAX_REQ 1024

struct packet_t {
	int ack;
	int seqnum;
	int checksum;
	char data[MAX_REQ];
};
typedef struct packet_t packet_t;

int isACK(int seqnum, int seq) {
	if (seqnum == seq) return 1;
	else return 0;
}

struct timeval settimer(void) {
	//(struct timeval rtt){
	//
	struct timeval timeout;
	timeout.tv_sec = 5;  // segundos
  	timeout.tv_usec = 0; // microssegundos
	return(timeout);
}



packet_t make_packet(unsigned char *msg, int msg_size, int seqnum){
	packet_t pck;
	bzero(&pck, sizeof(pck_t));
	pck.ack = 0;
	pck.seqnum = seqnum;
	pck.checksum(msg, msg_size);
	memcpy(pck.data, msg, msg_size);
	return (pck);
}

int seq_num = 0;

int rdt_send(int s, unsigned char *msg, int msg_size, struct sockaddr_in dst) {

	packet_t pck = make_packet(msg, msg_size, seqnum);

	do {
		// t1 = getttimeofday()
		ns = sendto(s, &pck, sizeof(pck_t), 0, &dst, sizeof(struct sockaddr_in));

		struct timeval = settimer(); // passar rtt aqui
		if (setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
  			perror("setsockop()");
    			return -1;
		}

		//printf("Aguardando confirmação seqnum=%d\n", seq);
		nr = recvfrom(s, (void *)&recvhdr, sizeof(struct header), 0,
                               		(struct sockaddr *)&caddr, &addr_len);
		if (nr < 0) {
		      	if (errno == EWOULDBLOCK || errno == EAGAIN) {
        			perror("socket timeout");
	     			continue;
        		}
		} else {
			// t2 = gettimeofday()
			// rtt = t2 - t1 // timeval ... timedif
			seq++;
			// atualizar o timer;
		}
	} while (nr < 0 || !isACK(recvhdr.seqnum, seq));

	return 0;
}

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
	// ./server <porta>
	if (argc != 2) {
		printf("%s <porta>\n", argv[0]);
		return 0;
	}

	int ls = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (ls == -1) {
		perror("socket()");
		return -1;
	}

	struct sockaddr_in addr;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(atoi(argv[1]));
	addr.sin_family = AF_INET;

	if (bind(ls, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
		perror("bind()");
		return -1;
	}

	int cfd, nr, n, checksum;
	char data[MAX_REQ];

	struct sockaddr_in caddr;
 	socklen_t addr_len;

	int seq = 0;
	while (1) {
		addr_len = sizeof(struct sockaddr_in);
		bzero(&caddr, addr_len);
		if (cfd == -1) {
			perror("accept()");
			close(ls);
			return -1;
		}
		cfd = ls;
		//printf("Aguardando requisição...\n");
		nr = recvfrom(cfd, (void *)&recvhdr, sizeof(struct header), 0,
				(struct sockaddr *)&caddr, &addr_len);

		//printf("Processando requisição...\n");
		if (seq == 0) strcpy(data, "pkt0");
		else strcpy(data, "pkt1");

		//checksum = getChecksum(data, 0);
		//make_pkt(seq, data, checksum);
		rdt_send(cfd, data, addr_len, caddr);

		/*do {
			//printf("Aguardando confirmação seqnum=%d\n", seq);
			n = recvfrom(cfd, (void *)&recvhdr, sizeof(struct header), 0,
                                		(struct sockaddr *)&caddr, &addr_len);
			if (n < 0) {
			      	if (errno == EWOULDBLOCK) {
        				perror("socket timeout");
		     			 udt_send(cfd, n, caddr, addr_len);
        			}
			}
		} while (n < 0 || !isACK(recvhdr.seqnum, seq));

		printf("Cliente IP(%s):Porta(%d): %d bytes: %s\n",
    		inet_ntoa(caddr.sin_addr),
     		 ntohs(caddr.sin_port),
     		 n,
    		  recvhdr.data);
   		 fflush(stdout);

		seq = (seq+1)%2;*/
	}
	close(ls);
	return 0;
}

