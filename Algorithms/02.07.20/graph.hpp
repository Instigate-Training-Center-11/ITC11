#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include<list>
#include <utility>
#include <string>
#include <iostream>

class Graph {
private:
    int print_size;
    int real_size;
    std::pair<std::list<int>, std::string>* my_city;

public:
    Graph();

    Graph(int real_size, int print_size = 0);

    ~Graph();

    /* For adding vertices */
    void add_city(int id, std::string city_name);

    /* For adding edges */
    void add_edge(int src, int dst);

    /* Printing all edges for vertices(id) */
    void print_edges(int id);

    /* Printing all vertices */
    void print_graph();
};

#endif