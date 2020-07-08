CC=g++
FLAG=-std=c++11
objects=main.o algorithm.o

make: $(objects)
	$(CC) $(FLAG) -o make $(objects)

main.o: algorithm.h main.cpp algorithm.cpp
	$(CC) $(FLAG) -c main.cpp

algorithm.o: algorithm.h algorithm.cpp
	$(CC) $(FLAG) -c algorithm.cpp

.PHONY: clean run
clean:
	rm -rf *.o
	rm -rf make
run:
	./make
