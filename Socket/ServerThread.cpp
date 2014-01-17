#include "ServerThread.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void* start_routineOne(void* parameter) {
    roomThread* room = (roomThread*) parameter;
    perror("fsfs");
    while(true) {        
        char* result = new char;
        int return_recv = room->sock1->recv(result);
        if (return_recv > 0) {
            puts("send to client 2");
            puts(room->sock2->getIpAddress());
            room->sock2->send(result);
            puts(result);
        }else{
            //deo nhan dc cai gi
        }
    }
    room->sock1->close();
    room->sock2->close();
    pthread_exit(NULL);
}

void* start_routineTwo(void* parameter) {
    roomThread* room = (roomThread*) parameter;
    perror("fsfs");
    while(true) {
        char* result = new char;
        int return_recv = room->sock2->recv(result);
        if (return_recv > 0) {
            puts("send to client 2");
            puts(room->sock1->getIpAddress());
            room->sock1->send(result);
            puts(result);
        }
        else{
            //deo nhan dc cai gi
        }
    }
    room->sock1->close();
    room->sock2->close();
    pthread_exit(NULL);
}

ServerThread::ServerThread(roomThread* room) {
    int rc = pthread_create(&thread, NULL, start_routineOne, (void*) room);
    int rc1 = pthread_create(&thread, NULL, start_routineTwo, (void*) room);
    if (rc || rc1) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
    }
}

