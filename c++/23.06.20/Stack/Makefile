CXX=g++

stack: stack.o main.o
		$(CXX) stack.o main.o -o stack

stack.o: stack.h stack.cpp
		$(CXX) -c stack.cpp

main.o: main.cpp
		$(CXX) -c main.cpp

.PHONY: run clean

run:
		./stack

clean:
		rm *.o stack

