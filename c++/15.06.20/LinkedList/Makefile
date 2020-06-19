CXX=g++

list: list.o main.o
			$(CXX) list.o main.o -o list

main.o: main.cpp
			$(CXX) -c main.cpp

list.o: list.hpp list.cpp
			$(CXX) -c list.cpp


run:
			./list

clean:
			rm *.o list
