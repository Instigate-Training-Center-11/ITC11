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
    g.add_city(5, "Sevan");

    /* Adding roads */
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(1, 5);
    g.add_edge(4, 5);

    std::cout << "My Graph" << std::endl << std::endl;

    /* All cities by ID */
    g.print_graph();

    g.print_edges(0);
    g.print_edges(1);
    g.print_edges(2);
    g.print_edges(3);
    g.print_edges(4);
    g.print_edges(5);

    return 0;
}

/*                              GRAPH                                 *
 *                                                                    *
 *        _________            _________            _________         *
 *       |Vanadzor |__________| Aparan  |__________| Erevan  |        *
 *       |__ID_0___|          |__ID_2___|          |__ID_1___|        *
 *            |     \                                   |             *
 *            |      \                                  |             *
 *            |       \                                 |             *
 *        ____|____    \ ________                   ____|____         *
 *       | Gyumri  |    |Dilijan |_________________|  Sevan  |        *
 *       |__ID_3___|    |__ID_4__|                 |__ID_5___|        *
 *                                                                    *
 *                                                                    *
 *                                                                    *
 */