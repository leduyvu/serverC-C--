#if !defined(_SERVERSOCKET_H)
#define _SERVERSOCKET_H

#include "Socket.h"

class ServerSocket : public Socket {
public:
  ServerSocket(int port);
  int bind();
  int listen(int numQueuedRequests);
  int accept();
};

#endif  //_SERVERSOCKET_H
