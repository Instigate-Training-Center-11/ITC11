CC=g++
FLAG=-std=c++11
objects=main.o BellmanFord.o

make: $(objects)
	$(CC) $(FLAG) -o make $(objects)

main.o: main.cpp
	$(CC) $(FLAG) -c main.cpp

bellmanford.o: BellmanFord.cpp
	$(CC) $(FLAG) -c BellmanFord.cpp

.PHONY: clean run
clean:
	rm -rf *.o
	rm -rf make
run:
	./make