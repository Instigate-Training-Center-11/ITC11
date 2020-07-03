#include <iostream>
#include "Graph.h"

int main() {
    /* Create the graph whit specified number of vertex. */
    int vertex = 5;
    Graph graph(vertex);
    int src = 0;

    std::cout << "Created the graph with 5 vertex. " << "\n";
    std::cout << "The short path from given '0' vertex the other vertexes is: " << "\n\n";

    /* Add vertex and egdes with weigth in the graph */
    graph.addEdge(0, 1, 100);
    graph.addEdge(0, 2, 110);
    graph.addEdge(0, 4, 120);
    graph.addEdge(1, 3, 130);
    graph.addEdge(2, 1, 160);
    graph.addEdge(2, 3, 150);
    graph.addEdge(3, 4, 140);
    graph.addEdge(4, 1, 170);
    graph.addEdge(4, 2, 180);

    /* Search the short path in the created graph. */
    graph.shortPath(src);

    return 0;
}