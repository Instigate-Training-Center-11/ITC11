CC=g++

search: search.o main.o
	$(CC) search.o main.o -o search

main.o: main.cpp
	$(CC) -c main.cpp

search.o: search.cpp
	$(CC) -c search.cpp

.PHONY: run clean

run:
	./search

clean:
	rm *.o search
