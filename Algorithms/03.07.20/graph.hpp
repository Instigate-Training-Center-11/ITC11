#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>


class Edge {
public:
    std::vector<std::pair<std::string, int>> edges;
};

class Graph {
private:
    /* All edges in class Edge, string in pair is name of vertex */
    std::map<std::string, Edge> my_city;

public:
    /* For adding vertices */
    void add_city(std::string city_name, std::string dst_name, int weight);

    /* Printing all vertices */
    void print(std::string name);

    /* Dijkstras algorithm for searching shortest path to destination */
    void dijkstras_path(std::string source, std::string dest);
};

#endif