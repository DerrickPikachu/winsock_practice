//
// Created by derrf on 2021/12/28.
//

#include <fstream>
#include "client.h"

/*
 * Constructor section
 */
Client::Client() {
    loadConfig();
    setupWSA();
    buildServerAddress();
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    connectToServer();
    std::cout << "connection successful" << std::endl;
    send(serverSocket, "test", 4, 0);
}

void Client::loadConfig() {
    std::ifstream config;
    config.open(configFile);
    if (!config.is_open()) {
        std::cerr << "file not found" << std::endl;
        exit(1);
    }
    std::string line;
    while (std::getline(config, line)) {
        std::string term = line.substr(0, line.find(":"));
        std::string value = line.substr(line.find(":") + 1);
        if (term == "ip") {
            ip = value;
        } else if (term == "port") {
            port = std::atoi(value.c_str());
        }
    }
}

void Client::setupWSA() {
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
        std::cerr << "wsa setup error" << std::endl;
        exit(1);
    }
}

void Client::buildServerAddress() {
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_addr.s_addr = inet_addr(ip.c_str());
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
}

void Client::connectToServer() {
    if (connect(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "connect error" << std::endl;
        exit(1);
    }
}

/*
 * Communication section
 */