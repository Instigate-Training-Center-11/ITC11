all: server client

server:
	g++ Server.cpp -o server -w

client: 
	g++ Client.cpp -o client -w