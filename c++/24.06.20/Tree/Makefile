CC=g++

tree: tree.o main.o
	$(CC) tree.o main.o -o tree

main.o: main.cpp
	$(CC) -c main.cpp

tree.o: tree.h tree.cpp
	$(CC) -c tree.cpp

.PHONY: run clean

run:
	./tree

clean:
	rm *.o tree
