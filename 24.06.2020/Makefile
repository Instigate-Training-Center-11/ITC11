CXX=g++

BST: node.o tree.o main.o
	$(CXX) node.o tree.o main.o -o BST

node.o: node.h node.cpp
	$(CXX) -c node.cpp

tree.o: tree.h tree.cpp
	$(CXX) -c tree.cpp

main.o: main.cpp
	$(CXX) -c main.cpp

.PHONY: run clean

run:
	./BST

clean:
	rm *.o BST
