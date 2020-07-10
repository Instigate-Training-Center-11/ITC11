#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Edge {
    public:
    std::vector<std::string> edge;
    std::vector<int> weight;
};

class Graph {
private:
    int print_size;
    int real_size;
    /* All edges in class Edge, string in pair is name of vertex */
    std::map<std::string, Edge> my_city;

public:

    /* For adding vertices */
    void add_city(std::string city_name, std::string dst_name, int weight);

    /* Printing all vertices */
    void print(std::string name);
};

#endif