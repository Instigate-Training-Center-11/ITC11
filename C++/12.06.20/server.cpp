#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

#define PORT 1789
#define ERROR "SERVER ERROR: "
#define MAGIC_WORD "exit"
#define BUFFER_SIZE 1024

bool client_close(const char*);

int socket_init();

int main() {
    int server = socket_init();

    char buffer[BUFFER_SIZE];
    bool is_exit = false;
    while (server > 0) {
        strcpy(buffer, "Server connected!\n");
        send(server, buffer, BUFFER_SIZE, 0);
        std::cout << "Connected client #1" << std::endl;
        std::cout << "Enter " << MAGIC_WORD << " to end the connection\n\n";
        std::cout << "Client: ";
        recv(server, buffer, BUFFER_SIZE, 0);
        std::cout << buffer << std::endl;
        if (client_close(buffer)) {
            is_exit = true;
        }

        while(!is_exit) {
            std::cout << "Server: ";
            std::cin.getline(buffer, BUFFER_SIZE);
            send(server, buffer, BUFFER_SIZE, 0);
            if (client_close(buffer)) {
                break;
            }

            std::cout << "Client: ";
            recv(server, buffer, BUFFER_SIZE, 0);
            std::cout << buffer << std::endl;
            if (client_close(buffer)) {

            }
        }
        std::cout << "\n Good bye..." << std::endl;
    }
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
    int server;
    int client;

    struct sockaddr_in ser_conf;
    client = socket(AF_INET, SOCK_STREAM, 0);

    socklen_t size = sizeof(ser_conf);

    if (client < 0) {
        std::cout << ERROR << "socket not created!\n";
        exit(0);
    }

    std::cout << "SERVER: socket was created\n";

    ser_conf.sin_port = htons(PORT);
    ser_conf.sin_family = AF_INET;
    ser_conf.sin_addr.s_addr = htons(INADDR_ANY);

    int ret = bind(client, (struct sockaddr*)(&ser_conf), size);
    if (ret < 0) {
        std::cout << ERROR << "binding...Socket already establishing.\n";
        return -1;
    }

    std::cout << "SERVER: " << "Listening....\n";
    listen(client, 1);

    server = accept(client, (struct sockaddr*)(&ser_conf), &size);
    if (server < 0) {
        std::cout << ERROR << "Eccepting fault...\n";
    }

    return server;
}