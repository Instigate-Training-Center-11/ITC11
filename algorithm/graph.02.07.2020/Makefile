CC=g++
FLAG=-std=c++11
objects=main.o graph.o

make: $(objects)
	$(CC) $(FLAG) -o make $(objects)

main.o: graph.h main.cpp graph.cpp
	$(CC) $(FLAG) -c main.cpp

graph.o: graph.h graph.cpp
	$(CC) $(FLAG) -c graph.cpp

.PHONY: clean run
clean:
	rm -rf *.o

run:
	./make
