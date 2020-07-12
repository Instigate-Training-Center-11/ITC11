CC=g++ #using compiler g++
CFLAGS=-std=c++11 #flag for compile target with c++11 standart
PROG=quick

${PROG}: quick_sort.hpp main.cpp quick_sort.cpp
	${CC} ${OBJECTS} main.cpp quick_sort.cpp -o ${PROG}

.PHONY: run

run:
	./${PROG}