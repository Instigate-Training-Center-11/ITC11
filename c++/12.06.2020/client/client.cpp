#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

#define PORT 1789
#define SERVER_IP "127.0.0.1"
#define MAGIC_WORD "exit"
#define BUFFER_SIZE 1024

bool client_close(const char* msg);

int socket_init();

int main() {
    int client = socket_init();

    char buffer[BUFFER_SIZE];
    recv(client, buffer, BUFFER_SIZE, 0);
    std::cout << "Connection established!\n";
    std::cout << "Enter " << MAGIC_WORD << " to end the connection\n\n";

    while (true) {
        std::cout << "Client: ";
        std::cin.getline(buffer, BUFFER_SIZE);
        send(client, buffer, BUFFER_SIZE, 0);
        if (client_close(buffer)) {
            break;
        }

        std::cout << "Server: ";
        recv(client, buffer, BUFFER_SIZE, 0);
        std::cout << buffer;
        if (client_close(buffer)) {
            break;
        }
        std::cout << std::endl;
    }
    close(client);
    std::cout << "Good bye...\n";
    return 0;
}

bool client_close(const char* msg) {
    std::string str = MAGIC_WORD;
    if (str == msg) {
        return true;
    }
    return false;
}

int socket_init() {
    int client;

    struct sockaddr_in ser_conf;
    client = socket(AF_INET, SOCK_STREAM, 0);

    socklen_t size = sizeof(ser_conf);

    if (client < 0) {
        std::cout << "Socket not created!\n";
        exit(0);
    }
    std::cout << "SERVER: socket was created\n";

    ser_conf.sin_port = htons(PORT);
    ser_conf.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_IP, &ser_conf.sin_addr);

    std::cout << "\nClient socket is created!\n";
    int ret = connect(client, (const struct sockaddr*)(&ser_conf), size);
    if (ret == 0) {
        std::cout << "Connection to server\n" << inet_ntoa(ser_conf.sin_addr);
        std::cout << " with port number: " << PORT << std::endl;
    }

    std::cout << "Waiting server confirmation..." << std::endl;
    return client;
}