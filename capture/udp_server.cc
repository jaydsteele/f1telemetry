#include "udp_server.h"
#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void udp_server(unsigned short port, std::ostream& out) {
  int sockfd;

  // create the socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    std::cerr << "Could not create socket" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::cout << "UDP Socket created" << std::endl;

  // handy trick to allow the socket server to be restarted quickly
  int optval = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));

  // build the server's internet address
  struct sockaddr_in addr;
  bzero((char *)&addr, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons((unsigned short)port);

  // bind to a port
  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    std::cerr << "Could not bind the socket" << std::endl;
  }
  std::cout << "Socket bound on port " << port << std::endl;

  std::cout << "Receiving data" << std::endl;
  // main loop
  int n;
  long totalData = 0;
  int count = 0;
  char buffer[BUFFER_SIZE];
  struct sockaddr_in clientAddr;
  socklen_t clientLen = sizeof(clientAddr);
  while (1) {
    n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0,
      (struct sockaddr *)&clientAddr, &clientLen);
    if (n < 0) {
      std::cerr << "Error receiving data" << std::endl;
      exit(EXIT_FAILURE);
    }
    out.write(buffer, n);
    totalData += n;
    if (count++ % 100 == 0) {
      std::cout << "Data received " << totalData << std::endl;
    }
  }

}
