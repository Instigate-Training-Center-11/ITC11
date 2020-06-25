CXX=g++
VERSION=--std=c++11

stack: stack.o main.o
	$(CXX) stack.o main.o -o stack

stack.o: stack.h stack.cpp
	$(CXX) -c stack.cpp $(VERSION)

main.o: main.cpp
	$(CXX) -c main.cpp $(VERSION)

.PHONY: run clean

run:
	./stack

clean:
	rm *.o stack 

