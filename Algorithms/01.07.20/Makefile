CC=g++ #using compiler g++
CFLAGS=-std=c++11 -o #flag for compile target with c++11 standart
OFLAGS=-c #flag for create objects
OBJECTS=main.o menu.o algorithm.o
PROG=search

${PROG}: ${OBJECTS}
	${CC} ${OBJECTS} ${CFLAGS} ${PROG}

main.o: algorithm.hpp menu.hpp main.cpp
	${CC} ${OFLAGS} main.cpp

menu.o: menu.hpp menu.cpp
	${CC} ${OFLAGS} menu.cpp

algorithm.o: algorithm.hpp algorithm.cpp
	${CC} ${OFLAGS} algorithm.cpp

.PHONY: run clean

run:
	./search

clean:
	\rm -f *.o