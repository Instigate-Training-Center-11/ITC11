CC=g++
FLAG=-std=c++11

client: client.o
	g++ client.o
	./a.out
	rm -rf a.out

client.o: client.cpp
	$(CC) -c client.cpp

.PHONY: clean run
clean:
	rm -rf *.o
