#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

#define INF 999999999

class Graph {
    private:
        int vertex;
        std::vector<std::pair<int, std::pair<int,int>>> edges;
        bool negative = false;
    public:
        Graph(int);
        void addEdge(int, int, int);
        void shortPath(int);
};

#endif