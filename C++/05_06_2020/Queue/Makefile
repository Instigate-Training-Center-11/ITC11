CC=g++ -std=c++11
runFile=queue_list
OBJECTS=Queue.o List.o Main.o

${runFile}: ${OBJECTS}
	${CC} $^ -o ${runFile}

Queue.o: Queue.cpp Queue.h
	${CC} -c $< -o $@

List.o: List.cpp List.h
	${CC} -c $< -o $@

Main.o: Main.cpp 
	${CC} -c $< -o $@

.PHONY: run

run: ./${runFile}

.PHONY: clean

clean:
	rm *.o ${runFile}
	echo "Object files are deleted."