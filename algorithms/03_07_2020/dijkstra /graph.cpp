#include "graph.h"

Graph::Graph(std::vector<Edges> const &Edgess, int size) {
    allList.resize(size);
    for(Edges const &Edges: Edgess) {
        allList[Edges.firstVertex].push_back(Edges);
    }
}