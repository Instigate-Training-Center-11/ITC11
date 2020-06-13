#include <fstream>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


int main() {
    	int sock = 0; 
	int listener = 0; 
	sockaddr_in addr;
    	//char buf[200];
    	int bytes_read;
    	listener = socket(AF_INET, SOCK_STREAM, 0);
    	addr.sin_family = AF_INET;
    	addr.sin_port = htons(8080);
    	addr.sin_addr.s_addr = htonl(INADDR_ANY);
    	if(bind(listener, (sockaddr *)&addr, sizeof(addr)) < 0) {
        	perror("bind");
        	exit(2);
    	}
    	listen(listener, 1);
        sock = accept(listener, NULL, NULL);
        if(sock < 0) {
            	perror("accept");
            	exit(3);
        }

	//get size of fail
	int buffer[1];
        bytes_read = recv(sock, buffer, 4, 0);

	int l = buffer[0];
	std::cout << l << std::endl;

	//create buffer by size of current fail
	char buff[l];
	bytes_read = recv(sock, buff, l, 0);
	std::cout << bytes_read << std::endl;
	//insert in new fail data
	std::ofstream ofs("new1.cpp");
	for(int i = 0; i < sizeof(buff); ++i) {
		ofs << buff[i];
	}
       	close(sock);
    
    	return 0;
}
