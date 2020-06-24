CC=g++ -std=c++11
runFile=tree
OBJECTS=Tree.o Main.o

${runFile}: ${OBJECTS}
	${CC} $^ -o ${runFile}

Tree.o: Tree.cpp Tree.h
	${CC} -c $< -o $@

Main.o: Main.cpp 
	${CC} -c $< -o $@

.PHONY: run

run: ./${runFile}

.PHONY: clean

clean:
	rm *.o ${runFile}
	echo "Object files are deleted."