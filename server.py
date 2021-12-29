import socket

class Server:
    def __init__(self):
        self.CONFIG_FILE = "sock.conf"
        self.ip, self.port = self.loadConfig()
        self.listenSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.listenSocket.bind((self.ip, self.port))
        self.listenSocket.listen(10)
        self.clientSocket = None

    def loadConfig(self):
        config = open(self.CONFIG_FILE)
        ip = ""
        port = 0
        for line in config.readlines():
            tokens = line.split(":")
            if tokens[0] == "ip":
                ip = tokens[1][:-1]
            elif tokens[0] == "port":
                port = int(tokens[1])
        print("ip: " + ip)
        print("port: " + str(port))
        return ip, port

    def waitClient(self):
        self.clientSocket, address = self.listenSocket.accept()


if __name__ == "__main__":
    server = Server()
    server.waitClient()