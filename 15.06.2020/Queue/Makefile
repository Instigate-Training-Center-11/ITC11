CXX=g++

queue: queue.o list.o main.o
	$(CXX) queue.o list.o main.o -o queue

%queue.o: %.h %.cpp
	$()CXX -c %.cpp

main.o: main.cpp
	$(CXX) -c main.cpp

.PHONY: run clean

run:
	./queue

clean:
	rm *.o queue
