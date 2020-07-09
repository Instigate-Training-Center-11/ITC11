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
    graph.addEdge(0, 1, 50);
    graph.addEdge(0, 3, 55);
    graph.addEdge(0, 4, -70);
    graph.addEdge(1, 2, 85);
    graph.addEdge(1, 3, 65);
    graph.addEdge(1, 4, 55);
    graph.addEdge(2, 0, 95);
    graph.addEdge(3, 2, -80);
    graph.addEdge(4, 2, 90);
    graph.addEdge(4, 3, 75);
    /*
     * In the terminal you will see this result.
     * 
     * 0 ->> 0
     * 1 ->> 50
     * 2 ->> -75
     * 3 ->> 5
     * 4 ->> -70
     */

    /* Search the short path in the created graph. */
    graph.shortPath(src);

    return 0;
}