#include <iostream>
using namespace std;
#define INT_MAX 32767

class Weight {
public:
	int nodeFrom;
	int nodeTo;
	int weight;
};

class Graph {
public:
	int V;
	int E;
	Weight* node;
};

Graph* createGraph(int V, int E) { 
	Graph* graph = new Graph;
	graph -> V = V;
	graph -> E = E;
	graph -> node = new Weight;

	return graph;
} 

void toString(int dist[], int n) {
	cout << "distance from src`" << endl;

	for(int i = 0; i < n; ++i) {
        	cout << i << '\t' << dist[i] << endl;
	}
}
 
void ford(Graph* graph, int nodeFrom) {
	int V = graph -> V;
	int E = graph->E;
	int dist[V];

	for(int i = 0; i < V; ++i) {
		dist[i] = INT_MAX;
	}

	dist[nodeFrom] = 0;

	for(int i = 1; i < V; ++i) {
		for(int j = 0; j < E; ++j) {
			int u = graph -> node[j].nodeFrom;
			int v = graph -> node[j].nodeTo;
			int weight = graph -> node[j].weight;

			if(dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
				dist[v] = dist[u] + weight;
			}
		}
	}

	for(int i = 0; i < E; ++i) {
		int u = graph->node[i].nodeFrom;
		int v = graph->node[i].nodeTo;
		int weight = graph->node[i].weight;

		if(dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
			cout << "Graph contains negative weight!" << endl;
			return;
		}
	}

	toString(dist, V);
	return;
} 
  
int main() {
	int V = 4;
	int E = 4;
	Graph* graph = createGraph(V, E);

	graph -> node[0].nodeFrom = 0;
	graph -> node[0].nodeTo = 1;
	graph -> node[0].weight = 1;
  
	graph -> node[1].nodeFrom = 0;
	graph -> node[1].nodeTo = 2;
	graph -> node[1].weight = 2;

	graph -> node[2].nodeFrom = 1;
	graph -> node[2].nodeTo = 2;
	graph -> node[2].weight = 3;

	graph -> node[3].nodeFrom = 1;
	graph -> node[3].nodeTo = 3;
	graph -> node[3].weight = 4;

	ford(graph, 0);

	return 0;
}
