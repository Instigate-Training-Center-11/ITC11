#include <iostream>
#include <vector>
#include <list>

struct Edges {
	int firstVertex;
    int lastVertex;
};

class Graph {
    public:
	    std::vector<std::list<int>> allVertex;
	    Graph(std::list<Edges> const &edges, int size) {
		    allVertex.resize(size);
		    for(auto edge: edges) {
			    allVertex[edge.firstVertex].push_back(edge.lastVertex);
		    }
	    }
};

void printGraph(Graph const& graph, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << i << " -> ";
		for (int vertex : graph.allVertex[i]) {
			std::cout << vertex << " ";
        }

		std::cout << std::endl;
	}
}

int main() {
    std::list<Edges> edges = {
		{0, 1}, {0, 2}, {1, 0}, {1, 2}, {1, 5}, {2, 3},
        {3, 2}, {3, 4}, {3, 5}, {4, 3}, {5, 1}, {5, 4},
	};

	int  size = 6;
	Graph graph(edges, size);
	printGraph(graph, size);

	return 0;
}