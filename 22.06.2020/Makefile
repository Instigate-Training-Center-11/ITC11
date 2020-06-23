CXX=g++

vector: vector.o main.o
	$(CXX) vector.o main.o -o vector

vector.o: iterator.h vector.h vector.cpp
	$(CXX) -c vector.cpp

main.o: main.cpp
	$(CXX) -c main.cpp

.PHONY: run clean

run:
	./vector

clean:
	rm *.o vector