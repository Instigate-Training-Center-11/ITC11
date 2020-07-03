#include<iostream>
#include "graph.hpp"

int main() {
    Graph g(10);

    /* Adding cities by ID */
    g.add_city(0, "Vanadzor");
    g.add_city(1, "Erevan");
    g.add_city(2, "Aparan");
    g.add_city(3, "Gyumri");
    g.add_city(4, "Dilijan");

    /* Adding roads */
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(4, 0);
    g.add_edge(4, 1);

    std::cout << "My Graph" << std::endl << std::endl;

    /* All cities by ID */
    g.print_graph();

    g.print_edges(0);
    g.print_edges(1);
    g.print_edges(2);
    g.print_edges(3);
    g.print_edges(4);

    return 0;
}