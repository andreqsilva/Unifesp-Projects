#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>

#define MAX_DATA_SIZE 100 // Maximum size of the data payload in a RDT packet
#define MAX_SEQ_NUMBER 10 // Maximum sequence number in the RDT protocol
#define TIMEOUT_MS 5000 // Timeout value in milliseconds
int SERVER_PORT=1234;

// Structure of an RDT packet
typedef struct {
  char data[MAX_DATA_SIZE]; // Data payload
  int seq; // Sequence number
  bool ack; // Acknowledgement flag
  bool fin; // Finish flag
} RdtPacket;


//------------------------------RDT send---------------------------------
void rdt_send(int sockfd, RdtPacket packet, struct sockaddr_in addr) {
  // Set the timeout value for the socket
  struct timeval tv;
  tv.tv_sec = 0;
  tv.tv_usec = TIMEOUT_MS * 1000;
  setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

  // Send the packet
  int n = sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&addr, sizeof(addr));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // Wait for an acknowledgement
  RdtPacket ack;
  socklen_t len = sizeof(addr);
  n = recvfrom(sockfd, &ack, sizeof(ack), 0, (struct sockaddr*)&addr, &len);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  // Check if the acknowledgement is correct
  if (!ack.ack || ack.seq != packet.seq) {
    // Retransmit the packet if the acknowledgement is not correct
    rdt_send(sockfd, packet, addr);
  }
}


//------------------------------RDT receive------------------------------------
void rdt_receive(int sockfd, RdtPacket *packet, struct sockaddr_in *addr) {
  // Set the timeout value for the socket
  struct timeval tv;
  tv.tv_sec = 0;
  tv.tv_usec = TIMEOUT_MS * 1000;
  setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

  // Wait for a packet
  socklen_t len = sizeof(*addr);
  int n = recvfrom(sockfd, packet, sizeof(*packet), 0, (struct sockaddr*)addr, &len);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  // Send an acknowledgement
  RdtPacket ack;
  ack.ack = true;
  ack.seq = packet->seq;
  n = sendto(sockfd, &ack, sizeof(ack), 0, (struct sockaddr*)addr, sizeof(*addr));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }
}