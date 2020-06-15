CC=g++ -std=c++11
CFLAGS=-c
SOURCES=server.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXE=server

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o: $(SOURCES)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean run

clean:
	rm $(OBJECTS) $(EXE)
	echo "Removed binary files and executable file";

run:
	./$(EXE)
