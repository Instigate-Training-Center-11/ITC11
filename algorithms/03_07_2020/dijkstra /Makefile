CC=g++ -std=c++11
CFLAGS=-c
SOURCES=main.cpp graph.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXE=graph

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