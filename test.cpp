//
// Created by derrf on 2021/12/29.
//
#include "client.h"

int main() {
    Client cli;
    std::string temp;
    std::getline(std::cin, temp);
    cli.sendSketch(temp);
    while (!cli.isNormalMapReady()) {
        std::cout << "hehehe" << std::endl;
    }
    std::cout << cli.recvNormalMap() << std::endl;
    return 0;
}