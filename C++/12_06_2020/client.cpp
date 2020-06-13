#include <fstream>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
	int sock;
  	sockaddr_in addr;

   	sock = socket(AF_INET, SOCK_STREAM, 0);
    	if(sock < 0) {
        	perror("socket");
        	exit(1);
    	}

    	addr.sin_family = AF_INET;
    	addr.sin_port = htons(8080);
    	addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    	if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        	perror("connect");
        	exit(2);
    	}

	char *buffer;
	long size;
	std::ifstream file("server.cpp",std::ios::in|std::ios::binary|std::ios::ate);
	size = file.tellg();
	file.seekg (0,std::ios::beg);
	buffer = new char [size];
	file.read (buffer,size);

	file.close();
	int *len = new int[1];
	len[0] = size;
    	send(sock, len, 4, 0);
	std::cout <<  len[0] << std::endl;
	
    	send(sock, buffer, size, 0);
    	close(sock);

    	return 0;
}
