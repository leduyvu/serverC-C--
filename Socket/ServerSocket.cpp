#include "ServerSocket.h"

ServerSocket::ServerSocket(int port) :
  Socket("localhost", port) {
}

int ServerSocket::bind() {
  struct sockaddr_in srv;
  srv.sin_family = AF_INET;
  srv.sin_port = htons(port);
  srv.sin_addr.s_addr = htonl(INADDR_ANY);
  int return_bind = ::bind(fd, (struct sockaddr*) &srv, sizeof(srv));
  if (return_bind < 0) {
    perror("bind");
    exit(1);
  } 
  return return_bind;
}

int ServerSocket::listen(int numQueuedRequests) {
  int return_listen = ::listen(fd, numQueuedRequests);
  if (return_listen < 0) {
    perror("listen");
    exit(1);
  }  
  return return_listen;
}

int ServerSocket::accept() {
  struct sockaddr_in cli;
  int newfd;
  socklen_t cli_len = sizeof(cli);
  newfd = ::accept(fd, (struct sockaddr*) &cli, &cli_len);
  if (newfd < 0) {
    perror("accept");
    exit(1);
  }  
  return newfd;
}
