#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "rdt.h"
#include <arpa/inet.h>
#include <arpa/inet.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
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
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(SERVER_PORT);
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

  // Set up the client address
  struct sockaddr_in cli_addr;
  memset(&cli_addr, 0, sizeof(cli_addr));
  socklen_t clilen = sizeof(cli_addr);

  // Initialize the message buffer and the expected sequence number
  char message[MAX_DATA_SIZE];
  memset(message, 0, MAX_DATA_SIZE);
  int seq = 0;

  while (1) {
    // Wait for a packet
    RdtPacket packet;
    rdt_receive(sockfd, &packet, &cli_addr);

    // Process the packet
    if (packet.seq == seq) {
      // Append the data to the message buffer if the sequence number is correct
      strncat(message, packet.data, MAX_DATA_SIZE-1);
      seq = (seq + 1) % (MAX_SEQ_NUMBER + 1);
    }

    // Check if the message is complete
    if (packet.fin) {
      printf("Received message: %s\n", message);
      break;
    }
  }

  return 0;
}