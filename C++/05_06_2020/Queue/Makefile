CC=g++

queue: Queue.o List.o  Main.o 
	${CC} Main.o List.o Queue.o -o queue

Queue.o: Queue.h Queue.cpp
	${CC} -c Queue.cpp -o Queue.o

List.o: List.h List.cpp
	${CC} -c List.cpp -o List.o

Main.o: Main.cpp 
	${CC} -c Main.cpp -o Main.o