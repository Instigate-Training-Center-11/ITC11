CC=g++
FLAG=-std=c++11
objects=main.o dijkstras.o

make: $(objects)
	$(CC) $(FLAG) -o make $(objects)

main.o: main.cpp
	$(CC) $(FLAG) -c main.cpp

dijkstras.o: dijkstras.cpp
	$(CC) $(FLAG) -c dijkstras.cpp

.PHONY: clean run
clean:
	rm -rf *.o
	rm -rf make
run:
	./make
