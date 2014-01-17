#if !defined(_SERVERTHREAD_H)
#define _SERVERTHREAD_H

#include "Socket.h"
#include <stdio.h>
#include <pthread.h>

class ServerThread {
public:
//  Server* server;
  pthread_t thread;
  ServerThread(roomThread* room);
};

#endif  //_SERVERTHREAD_H
