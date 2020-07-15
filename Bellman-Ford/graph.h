#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <limits>
#include <map>


class Graph {
    struct Vertex {
        std::size_t id;
        int distance = std::numeric_limits<int>::max();
        Vertex(std::size_t id) : id(id) {}
    };

    std::vector<Vertex> vertices;
    std::map<std::pair<std::size_t, std::size_t>, int> edge_weight;

  public:
    Graph(std::size_t);
    void add_edge(std::size_t, std::size_t, int); //source, destination, weight
    bool bellman_ford(std::size_t); //source
    void distance_from_source();

  private:
    void relax(std::size_t, std::size_t, int); //source, destination, weight
};

#endif