#include "ServerSocket.h"
#include "Socket.h"
#include "ServerThread.h"
#include <stdio.h>
#include <string.h>
#include <pthread.h>

int main(int argc, char* argv[]) {
    int port= 8080;
    //  if(argc == 2){
    //    port = atoi(argv[1]);
    //  }
    printf("server started...\n");
    ServerSocket ss( port);
    int opt = 1;
    setsockopt(ss.fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    ss.bind();
    ss.listen(5);
    int newfd;
    Socket* s;
    int i=0;
    int number = 0;
    roomThread *roomAll = new roomThread;
    int index = 0;
    while (1) {
        newfd = ss.accept();
        printf("accept client count %d\n", i);
        Socket *s1 = new Socket(newfd);
        s1->port = port;
        printf("fd:::::: %d", s1->fd);
        if(number == 0){
            (roomAll + index)->sock1 = s1;
            number++;
        }
        else {
            number = 0;
            (roomAll + index)->sock2 = s1;
            new ServerThread(roomAll + index);
            index++;
        }
        i++;
    }
    pthread_exit(NULL);
    return 0;
}
