CC=g++ -std=c++11
runFile=client

${runFile}: client.o
	g++ client.o -o ${runFile}

client.o: client.cpp 
	g++ -c $< -o $@

.PHONY: run

run: ./${runFile}

.PHONY: clean

clean:
	rm *.o ${runFile}
	echo "Object files are deleted from client."