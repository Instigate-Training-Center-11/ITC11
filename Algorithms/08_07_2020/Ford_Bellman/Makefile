CC=g++ -std=c++11
runFile=graph
OBJECTS=Graph.o Main.o

${runFile}: ${OBJECTS}
	${CC} $^ -o ${runFile}

Graph.o: Graph.cpp Graph.h
	${CC} -c $< -o $@

Main.o: Main.cpp 
	${CC} -c $< -o $@

.PHONY: run

run: ./${runFile}

.PHONY: clean

clean:
	rm *.o ${runFile}
	echo "Object files are deleted."