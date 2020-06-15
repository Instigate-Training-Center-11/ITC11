CXX=g++
SOMEFLAG=-c

somename: main.o List.o Node.o
	$(CXX) $< List.o Node.o -o $@

main.o: main.cpp
	$(CXX) $(SOMEFLAG) $<

List.o: List.cpp
	$(CXX) $(SOMEFLAG) $<

Node.o: Node.cpp
	$(CXX) $(SOMEFLAG) $<

clean:
	rm -rf *.o $@