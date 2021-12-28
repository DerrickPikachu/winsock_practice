//
// Created by derrf on 2021/12/27.
//

#undef UNICODE

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
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT 27015

int __cdecl main(int argc, char** argv) {
//    int port = std::atoi(argv[1]);
    WSADATA wsadata;

    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
        std::cerr << "wsa error" << std::endl;
        return 1;
    }

    SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    SOCKADDR_IN serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(DEFAULT_PORT);
    if (connect(s, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "connect error" << std::endl;
        return 1;
    }

    std::string buffer;
    char recvBuffer[512];
    while (std::getline(std::cin, buffer)) {
        if (send(s, buffer.c_str(), buffer.size(), 0) == SOCKET_ERROR) {
            std::cerr << "send error" << std::endl;
            return 1;
        }
        if (recv(s, recvBuffer, 512, 0) == SOCKET_ERROR) {
            std::cerr << "recv error" << std::endl;
            return 1;
        }
        std::cout << recvBuffer << std::endl;
        memset(recvBuffer, 0, 512);
    }
    return 0;
}