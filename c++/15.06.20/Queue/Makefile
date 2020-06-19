CXX=g++

list: queue.o list.o main.o
		$(CXX) queue.o list.o main.o -o q_list

main.o: main.cpp
		$(CXX) -c main.cpp

list.o: list.hpp list.cpp
		$(CXX) -c list.cpp

queue.o: queue.hpp queue.cpp
		$(CXX) -c queue.cpp

run:
		./q_list

clean:
		rm *.o q_list
