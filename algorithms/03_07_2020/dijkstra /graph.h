#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

struct Edges {
	int firstVertex;
	int lastVertex;
	int weight;
};

struct Node {
	int vertex;
	int weight;
};

class Graph {
public:
	std::vector<std::vector<Edges>> allList;
	Graph(std::vector<Edges> const &, int);
};


#endif