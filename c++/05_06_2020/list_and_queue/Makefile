queue: queue.o list.o node.o main.o
	echo "Make exe file queue"
	g++ main.o list.o queue.o node.o -o queue
queue.o: queue.h queue.cpp
	g++ -c queue.cpp -o $@
list.o: list.h list.cpp
	g++ -c list.cpp -o $@
node.o: node.h node.cpp
	g++ -c node.cpp -o $@
main.o: main.cpp
	g++ -c main.cpp -o $@
.PHONY: clean

clean:
	rm *.o
	rm queue


