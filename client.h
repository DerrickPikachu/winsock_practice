//
// Created by derrf on 2021/12/28.
//

#ifndef WINSOCK_PRACTICE_CLIENT_H
#define WINSOCK_PRACTICE_CLIENT_H

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")

class Client {
public:
    Client();

private:
    void setupWSA();
    void buildServerAddress();
    void loadConfig();
    void connectToServer();

private:
    WSADATA wsadata;
    SOCKET serverSocket;
    SOCKADDR_IN serverAddress;
    int port;
    std::string ip;
    const int MAX_BUFFER = 512;
    const std::string configFile = "sock.conf";
};


#endif //WINSOCK_PRACTICE_CLIENT_H
