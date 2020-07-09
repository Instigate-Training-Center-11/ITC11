#include <iostream>
#include "Graph.h"

/* Constructor */
Graph::Graph(int vertex) {
    this->vertex = vertex;
}

/* Add edge in graph. */
void Graph::addEdge(int u, int v, int w) {
    edges.push_back({w, {u, v}});
}

/* Ford Bellman algorithm. */
void Graph::shortPath(int src) {
    std::vector<int> distance(this->vertex, INF);
    std::vector<std::pair<int, std::pair<int, int>>>::iterator it;
    distance[src] = 0;

    for (int i = 1; i < this->vertex; ++i) {
        for (it = edges.begin(); it != edges.end(); ++it) {
            int u = it->second.first;
            int v = it->second.second;
            int w = it->first;
            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }
       
    for (it = edges.begin(); it != edges.end(); ++it) {
        int u = it->second.first;
        int v = it->second.second;
        int w = it->first;
        if (distance[u] + w < distance[v]) {
            this->negative = true;
        }
    }
        
    if (!negative) {
        for (int i = 0; i < vertex; ++i) {
            std::cout << i << " ->> " << distance[i] << "\n";
        }
    }
}