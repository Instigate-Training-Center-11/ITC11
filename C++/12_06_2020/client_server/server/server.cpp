#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
 
int main() {
    /* Create a socket, IPv4, TCP, pratacol. */
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == listening) {
        std::cerr << "Can not create a socket." << "\n";
        return -1;
    }
 
    /* Bind the IP  and PORT to socket. */
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(3000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);
    bind(listening, (sockaddr*)&hint, sizeof(hint));
 
    /* Listening. */
    listen(listening, SOMAXCONN);
 
    /* Wait for connection. */
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
    
    /* accept a connection on a socket */
    int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);
    char host[NI_MAXHOST];   
    char service[NI_MAXSERV];
    memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);
 
    /*
    If getnameinfo() not return 0, then error.
    getnameinfo - address-to-name translation in protocol-independent manner.
    */
    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
        std::cout << host << " connected on port " << service << "\n";
    } else {
        /* inet_ntop - convert IPv4 and IPv6 addresses from binary to text form. */
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        /* ntohs - convert values between host and network byte order. */
        std::cout << host << " connected on port " << ntohs(client.sin_port) << "\n";
    }
 
    /* Close the listening socket. */
    close(listening);
    char buf[4096];
 
    while (true) {
        memset(buf, 0, 4096);
 
        /* Wait for client to sending the data. */
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (-1 == bytesReceived) {
            std::cerr << "Error in recv()" << "\n";
            break;
        }
        if (0 == bytesReceived) {
            std::cout << "Client disconnected" << "\n";
            break;
        }        
        std::cout << std::string(buf, 0, bytesReceived) << "\n";
 
        /* Print the message back to client. */
        send(clientSocket, buf, bytesReceived + 1, 0);
    }

    /* Close the socket */
    close(clientSocket);
 
    return 0;
}