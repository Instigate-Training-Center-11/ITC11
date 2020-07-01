CC=g++ -std=c++11
runFile=search
OBJECTS=main.o

${runFile}: ${OBJECTS}
	${CC} $^ -o ${runFile}

main.o: main.cpp
	${CC} -c $< -o $@

.PHONY: run

run: ./${runFile}

.PHONY: clean

clean:
	rm *.o ${runFile}
	echo "Object files are deleted."