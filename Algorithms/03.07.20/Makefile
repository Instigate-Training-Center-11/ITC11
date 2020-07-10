CC=g++ #using compiler g++
CFLAGS=-std=c++11 -o #flag for compile target with c++11 standart
SOURCE=main.cpp graph.cpp
PROG=Dijkstra

${PROG}: graph.hpp ${SOURCE}
	${CC} ${SOURCE} ${CFLAGS} ${PROG}

.PHONY: run

run:
	./${PROG}