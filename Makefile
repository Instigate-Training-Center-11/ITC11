CC = g++
thread.o: thread.cpp
		${CC} -Wall -g -std=c++11 -pthread thread.cpp
clean:
		rm -rf *.o