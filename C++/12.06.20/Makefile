CC=g++ #using compiler g++
CFLAGS=-std=c++11 -o #flag for compile target with c++11 standart
OFLAGS=-c #flag for create objects
PROG=server_list
PROG1=server
PROG2=client
OBJECT1=server.o
OBJECT2=client.o
SERVSRC=server.cpp
CLTSRC=client.cpp

${PROG}: ${OBJECT1} ${OBJECT2}
	${CC} ${OBJECT1} ${CFLAGS} ${PROG1}
	${CC} ${OBJECT2} ${CFLAGS} ${PROG2}

${OBJECT1}: ${SERVSRC}
	${CC} ${OFLAGS} ${SERVSRC}
${OBJECT2}: ${CLTSRC}
	${CC} ${OFLAGS} ${CLTSRC}

.PHONY: clean

clean:
	\rm -f *.o