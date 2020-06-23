CC=g++ -std=c++11
runFile=vector
OBJECTS=Vector.o Main.o

${runFile}: ${OBJECTS}
	${CC} $^ -o ${runFile}

List.o: Vector.cpp Vector.h
	${CC} -c $< -o $@

Main.o: Main.cpp 
	${CC} -c $< -o $@

.PHONY: run

run: ./${runFile}

.PHONY: clean

clean:
	rm *.o ${runFile}
	echo "Object files are deleted."