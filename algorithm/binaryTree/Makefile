CC=g++
FLAG=-std=c++11
objects=main.o binaryTree.o

make: $(objects)
	$(CC) $(FLAG) -o make $(objects)

main.o: main.cpp
	$(CC) $(FLAG) -c main.cpp

binaryTree.o: binaryTree.cpp
	$(CC) $(FLAG) -c binaryTree.cpp

.PHONY: clean run
clean:
	rm -rf *.o
	rm -rf make
run:
	./make
