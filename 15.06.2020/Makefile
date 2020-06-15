CXX=g++

list: list.o main.o
	$(CXX) list.o main.o -o list

main.o: main.h main.cpp
	$(CXX) -c main.cpp

list.o: list.h list.cpp
	$(CXX) -c list.cpp

.PHONY: run clean
run:
	./list

clean:
	rm *.o list
