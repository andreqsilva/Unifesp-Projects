#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "rdt.h"
#include <arpa/inet.h>
#include <stdbool.h>


int main(int argc, char *argv[]) {
  // Check the command line arguments
  if (argc < 2) {
    fprintf(stderr, "Usage: %s hostname message\n", argv[0]);
    exit(1);
  }

  // Get the hostname and message from the command line
  char *message = argv[2];
  char *hostname = "localhost";

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Set up the server address
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(SERVER_PORT);
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
  int rv = inet_pton(AF_INET, hostname,&serv_addr.sin_addr);
  if (rv == 0) {
    perror("No valid string representing a valid network adress");
    }
  if(rv<0) {
    perror("No correct adress family");
    exit(1);
  }

  // Split the message into packets and send them one by one
  int seq = 0;
  int len = strlen(message);
  for (int i = 0; i < len; i += MAX_DATA_SIZE) {
    // Create a packet
    RdtPacket packet;
    memset(packet.data, 0, MAX_DATA_SIZE);
    strncpy(packet.data, message + i, MAX_DATA_SIZE);
    packet.seq = seq;
    packet.ack = false;
    packet.fin = (i + MAX_DATA_SIZE >= len);

    // Send the packet
    rdt_send(sockfd, packet, serv_addr);

    // Increment the sequence number
    seq = (seq + 1) % (MAX_SEQ_NUMBER + 1);
  }

  return 0;
}