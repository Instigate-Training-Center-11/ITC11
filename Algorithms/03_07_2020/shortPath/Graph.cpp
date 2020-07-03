#include <iostream>
#include <queue>
#include "Graph.h"

/* Constructor */
Graph::Graph(int vertex) {
    this->vertex = vertex;
    adgList = new std::list<myPair>[this->vertex];
}

/* Add edge in graph. */
void Graph::addEdge(int u, int v, int w) {
    adgList[u].push_back({v, w});
    adgList[v].push_back({u, w});
}

/* Deykstra algorithm. */
void Graph::shortPath(int src) {
    /* In priority queue the first element is the largest from the rest. */
    std::list<myPair>::iterator it;
    std::priority_queue<myPair, std::vector<myPair>, std::greater<myPair>> prQueue;
    std::vector<int> distance(this->vertex, INF);

    distance[src] = 0;
    prQueue.push({0, src});

    while (!prQueue.empty()) {
        int u = prQueue.top().second;
        prQueue.pop();

        for (it = adgList[u].begin(); it != adgList[u].end(); ++it) {
            int v = it->first;
            int w = it->second;
            if (distance[v] > distance[u] + w){
                distance[v] = distance[u] + w;
                prQueue.push({distance[v], v});
            }
        }
    }

    for (int i = 0; i < this->vertex; ++i) {
        std::cout << i << " ->> " << distance[i] << "\n";
    }
}