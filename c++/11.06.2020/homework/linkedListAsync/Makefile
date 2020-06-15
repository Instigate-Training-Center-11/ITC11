flags = -std=c++11 -pthread
compiler=g++

buildg: main.o list.o node.o
	${compiler} main.o list.o node.o ${flags} -o build

main.o: main.cpp
	${compiler} main.cpp -c ${flags} 

list.o: list.cpp
	${compiler} list.cpp -c ${flags} 

node.o: node.cpp
	${compiler} node.cpp -c ${flags} 

.PHONY: clean
clean:
	rm -f *.o build

.PHONY: run
run:
	./build
