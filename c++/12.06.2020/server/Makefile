
CC=g++
FLAG=-std=c++11

server: server.o
	gnome-terminal -x sh -c './server.o; ./a.out; exec bash'

server.o: server.cpp
	$(CC) -c server.cpp

.PHONY: clean run
clean:
	rm -rf *.o
