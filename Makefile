CC=g++
Start.o: Start.cpp 
	g++ -c Start.cpp -o Start.o
clean:
	rm -rf *.o
