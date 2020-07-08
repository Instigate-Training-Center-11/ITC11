#include <iostream>
#include <vector>

#include "graph.h"

#define INT_MAX 10000 /* infinity */

void printArr(std::vector<int>, int);
void bellmanFord(Graph *, int);


int main() {
    int V = 5;                          /* Count of vertixes */
    int E = 8;                          /* Count of edges */
    std::vector<Edge> edges = {         /* All edges */
		{0, 1, 10}, {0, 4, -20}, {1, 2, 30}, {1, 4, 40}, {2, 3, 50},
		{3, 2, 60}, {4, 1, 70}, {4, 2, -80}, {4, 3, 90}, {1, 0, -5}
	};

    Graph graph(edges, V, E);           /* Create Graph object */
    bellmanFord(&graph, 0);
    bellmanFord(&graph, 1);
    bellmanFord(&graph, 2);
    bellmanFord(&graph, 3);
    bellmanFord(&graph, 4);

    return 0;
}

/* This function printed vector */
void printArr(std::vector<int> vec, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << vec[i] << '\t';
    }

    std::cout << std::endl;
}

/* Implimentation algorithm Bellman Ford */
void bellmanFord(Graph* graph, int beginVertix) {
    int V = graph->countV;
    int E = graph->countE;
    std::vector<int> distance;

    for(int i = 0; i < V; ++i) {
        distance.push_back(INT_MAX);
    }

    distance[beginVertix] = 0;
    for(int i = 1; i <= V - 1; ++i) {
        for(int j = 0; j < E; ++j) {
            int first = graph->edges[j].firstVertix;
            int last = graph->edges[j].lastVertix;
            int weight = graph->edges[j].weight;
            if(distance[first] != INT_MAX && (distance[first] + weight < distance[last])) {
                distance[last] = distance[first] + weight;
            }
        }
    }

    for(int i = 0; i < E; ++i) {
        int first = graph->edges[i].firstVertix;
        int last = graph->edges[i].lastVertix;
        int weight = graph->edges[i].weight;
        if(distance[first] != INT_MAX && (distance[first] + weight < distance[last])) {
            std::cout << "Graph has cycle with negative weight" << std::endl;
            return;
        }
    }

    std::cout << beginVertix << " -->\t";
    printArr(distance, V);

    return;
}