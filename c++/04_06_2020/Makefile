CC=g++
FLAG=-std=c++11
objects=main.o list.o

edit: $(objects)
	$(CC) $(FLAG) -o edit $(objects)

main.o: list.hpp main.cpp
	$(CC) -c main.cpp

list.o: list.hpp list.cpp
	$(CC) -c list.cpp

.PHONY: clean run
clean:
	rm -rf *.o
