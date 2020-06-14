#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    /* Create a socket, IPv4, TCP, PRATACOL. */
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sock) {
        return 1;
    }

    /* Create a hint structure for the server to connecting. */
    int port = 3000;
    std::string ipAddress = "127.0.0.1";
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    char buf[4096];
    std::string userInput;

    /* inet_pton - convert IPv4 and IPv6 addresses from text to binary form. */
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    /* Connect to the server on the socket. */
    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if (-1 == connectRes) {
        return 1;
    }
    do {
        /* Enter text. */
        std::cout << "> ";
        std::getline(std::cin, userInput);

        /* Send data to the server. */
        int sendRes = send(sock, userInput.c_str(), userInput.size() + 1, 0);
        if (-1 == sendRes) {
            std::cout << "Can not send data to server!\n";
            continue;
        }
        /* Wait for response. */
        memset(buf, 0, 4096);

        /* recv - receive a message from a socket. */
        int bytesReceived = recv(sock, buf, 4096, 0);
        if (-1 == bytesReceived) {
            std::cout << "Error from getting response from server\n";
        } else {
            /* Display response. */
            std::cout << "From Server>>> " << std::string(buf, bytesReceived) << "\n";
        }
    } while(true);
    
    /* Close the socket. */
    close(sock);

    return 0;
}