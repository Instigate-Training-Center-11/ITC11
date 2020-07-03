#include <iostream>
#include <vector>
#include <queue>

#include"graph.h"

#define INT_MAX 100

void printFirstVertex(std::vector<int> const &prev, int i) {
	if(0 > i) {
		return;
	}

	printFirstVertex(prev, prev[i]);
	std::cout << i << " ";
}

struct comp {
	bool operator()(const Node &left, const Node &right) {
		return left.weight > right.weight;
	}
};

void shortestPath(Graph const& graph, int firstVertex, int size) {
	std::priority_queue<Node, std::vector<Node>, comp> edge;
	edge.push({firstVertex, 0});
	std::vector<int> distanc(size, INT_MAX);

	distanc[firstVertex] = 0;
	std::vector<int> prev(size, -1);

	while(!edge.empty()) {
		Node node = edge.top();
		edge.pop();
		int current = node.vertex;

		for(auto i : graph.allList[current]) {
			int currVertex = i.lastVertex;
			int weight = i.weight;

			if((distanc[current] + weight) < distanc[currVertex]) {
				distanc[currVertex] = distanc[current] + weight;
				prev[currVertex] = current;
				edge.push({currVertex, distanc[currVertex]});
			}
		}
	}

	for(int i = 0; i < size; ++i) {
		if(i != firstVertex && distanc[i] != INT_MAX) {
			std::cout << "Path (" << firstVertex << " -> " << i << "): Minimum Path = " << distanc[i] << " All vertex[ ";
			printFirstVertex(prev, i);
			std::cout << "]" << std::endl;
		}
	}
}

int main() {
	std::vector<Edges> edges = {
		{0, 1, 10}, {0, 4, 20}, {1, 2, 30}, {1, 4, 40}, {2, 3, 50},
		{3, 2, 60}, {4, 1, 70}, {4, 2, 80}, {4, 3, 90}, {1, 0, 5}
	};

	int size = 5;
	Graph graph(edges, size);
	int firstVertex = 1;
	shortestPath(graph, firstVertex, size);

	return 0;
}