CC=g++ #using compiler g++
CFLAGS=-std=c++11 #flag for compile target with c++11 standart
PROG=sort

${PROG}: sorting_algorithm.hpp main.cpp sorting_algorithm.cpp
	${CC} ${OBJECTS} main.cpp sorting_algorithm.cpp -o ${PROG}

.PHONY: run

run:
	./${PROG}