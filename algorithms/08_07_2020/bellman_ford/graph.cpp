#include "graph.h"

/* Constructor */
Graph::Graph(std::vector<Edge> const &reb, int V, int E) {
    this->countE = E;
    this->countV = V;
    this->edges.resize(E);

    for(int i = 0; i < reb.size(); ++i) {
        edges[i].firstVertix = reb[i].firstVertix;
        edges[i].lastVertix = reb[i].lastVertix;
        edges[i].weight = reb[i].weight;
    }
}