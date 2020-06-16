CC=g++ #using compiler g++
CFLAGS=-std=c++11 -o #flag for compile target with c++11 standart
OFLAGS=-c #flag for create objects
OBJECTS=main.o list.o
PROG=list

${PROG}: ${OBJECTS}
	${CC} ${OBJECTS} ${CFLAGS} ${PROG}

main.o: list.hpp main.cpp
	${CC} ${OFLAGS} main.cpp

list.o: list.hpp node.hpp list.cpp
	${CC} ${OFLAGS} list.cpp

.PHONY: clean

clean:
	\rm -f *.o