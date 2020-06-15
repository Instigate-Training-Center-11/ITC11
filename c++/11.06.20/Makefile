CC=g++
flags= -std=c++11 -pthread

list: main.o list.o
			$(CC) main.o list.o $(flags) -o list

main.o: main.cpp
			$(CC) main.cpp -c $(flags)

list.o: list.cpp list.hpp
			$(CC) list.cpp -c $(flags)

.PHONY: clean
clean:
			rm  -f *.o list

.PHONY: run
run:
	^I^I./list
