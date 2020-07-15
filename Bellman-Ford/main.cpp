#include "graph.h"

int main()
{
    Graph grp(5);
    grp.add_edge(0, 1, 6);
    grp.add_edge(0, 2, 7);
    grp.add_edge(1, 3, 5);
    grp.add_edge(1, 4, -4);
    grp.add_edge(1, 2, 8);
    grp.add_edge(2, 3, -3);
    grp.add_edge(2, 4, 9);
    grp.add_edge(3, 1, -2);
    grp.add_edge(4, 0, 2);
    grp.add_edge(4, 3, 7);

    bool res = grp.bellman_ford(0);
    if (res == true)
       std::cout << "Graph contains no negative cycle \n";
    else
       std::cout << "Graph conatains negative cycle \n";

    grp.distance_from_source();
}