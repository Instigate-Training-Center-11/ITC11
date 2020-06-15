CC=g++ -std=c++11
runFile=server

${runFile}: server.o
	g++ server.o -o ${runFile}

client.o: server.cpp 
	g++ -c $< -o $@

.PHONY: run

run: ./${runFile}

.PHONY: clean

clean:
	rm *.o ${runFile}
	echo "Object files are deleted from server."