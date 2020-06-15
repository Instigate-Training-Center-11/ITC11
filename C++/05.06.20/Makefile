#using compiler g++
CC=g++
OBJECTS=main.o list.o queue.o
HEADER=list.hpp queue.hpp node.hpp

list: ${OBJECTS}
	${CC} -lm ${OBJECTS} -o list

main.o: ${HEADER} main.cpp
	${CC} -c main.cpp -o main.o

list.o: ${HEADER} list.cpp
	${CC} -c list.cpp -o list.o

queue.o: ${HEADER} queue.cpp
	${CC} -c queue.cpp -o queue.o

.PHONY: clean run

clean:
	\rm -f *.o