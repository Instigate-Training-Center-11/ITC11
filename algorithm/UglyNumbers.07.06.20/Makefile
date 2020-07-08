CC=g++
FLAG=-std=c++11
objects=main.o ugly.o

make: $(objects)
	$(CC) $(FLAG) -o make $(objects)

main.o: main.cpp
	$(CC) $(FLAG) -c main.cpp

ugly.o:  ugly.cpp
	$(CC) $(FLAG) -c ugly.cpp

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf make
run:
	./make
