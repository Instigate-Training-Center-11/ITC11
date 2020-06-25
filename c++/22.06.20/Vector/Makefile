CXX=g++

vector: vector.o vmain.o
		$(CXX) vector.o vmain.o -o vector

vector.o: iterator.h vector.h vector.cpp
		$(CXX) -c vector.cpp

vmain.o: vmain.cpp
		$(CXX) -c vmain.cpp

.PHONY: run clean

run:
		./vector

clean:
		rm *.o vector

