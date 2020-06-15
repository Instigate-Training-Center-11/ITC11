CC=g++
FLAG=-std=c++11
objects=main.o list.o queue.o

list: $(objects)
	$(CC) $(FLAG) -o list $(objects)

main.o: list.hpp queue.hpp main.cpp
	$(CC) $(FLAG) -c main.cpp

list.o: list.hpp list.cpp
	$(CC) $(FLAG) -c list.cpp

queue.o: queue.hpp queue.cpp
	$(CC) $(FLAG) -c queue.cpp

.PHONY: clean run
clean:
	rm -rf *.o
