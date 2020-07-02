CC=g++ #using compiler g++
CFLAGS=-std=c++11 -o #flag for compile target with c++11 standart
HEADERS=menu.hpp linear_search.hpp binary_search.hpp jump_search.hpp interpolation_search.hpp exponential_search.hpp ternary_search.hpp
PROG=search

${PROG}: ${HEADERS} main.cpp
	${CC} main.cpp ${CFLAGS} ${PROG}

.PHONY: run

run:
	./search