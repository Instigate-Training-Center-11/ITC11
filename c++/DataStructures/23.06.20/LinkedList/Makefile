CXX=g++

dList: list.o main.o
	$(CXX) list.o main.o -o dList

list.o: iterator.h list.h list.cpp
	$(CXX) -c list.cpp

main.o: main.cpp
	$(CXX) -c main.cpp

.PHONY: run clean

run:
	./dList

clean:
	rm *.o dList
