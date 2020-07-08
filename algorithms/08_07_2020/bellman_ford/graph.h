#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

    struct Edge {
        int firstVertix;
        int lastVertix;
        int weight;
    };

    /* Create user type Graph */
    class Graph {
        public:
        int countV;
        int countE;
        std::vector<Edge> edges;
        Graph(std::vector<Edge> const &, int, int);
    };

#endif