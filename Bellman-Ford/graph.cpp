#include "graph.h"

Graph::Graph(std::size_t size) {
    vertices.reserve(size);
    for (int i = 0; i < size; ++i) {
        vertices.push_back(Vertex(i));
    }
}

void Graph::add_edge(std::size_t src, std::size_t dest, int weight) {
    if (src == dest) {
        std::cout << "Source and destination vertices are same" << std::endl;
    }

    if (src < 0 || vertices.size() <= src) {
        std::cout << "Enter correct source vertex" << std::endl;
    }

    if (dest < 0 || vertices.size() <= dest) {
        std::cout << "Enter correct destination vertex" << std::endl;
    }

    const auto inserted = edge_weight.insert(std::make_pair(std::make_pair(src, dest), weight ));
    if (!inserted.second) {
        std::cout << "Existing edge" << std::endl;
    }

}

void Graph::relax(std::size_t src, std::size_t dest, int weight) {
    if (vertices[dest].distance > (vertices[src].distance + weight)) {
        vertices[dest].distance = (vertices[src].distance + weight);
    }
}

bool Graph::bellman_ford(std::size_t src) {
    //initialize distance of source
    vertices[src].distance = 0;

    for (int i = 0; i < vertices.size() - 1; ++i) {
        for (auto it = edge_weight.begin(); it != edge_weight.end(); ++it) {
            relax(it->first.first, it->first.second, it->second);
        }
    }

    for (auto it = edge_weight.begin(); it != edge_weight.end(); ++it) {
        if (vertices[it->first.second].distance > (vertices[it->first.first].distance + it->second)) {
            return false;
        }
    }

    return true;
}


void Graph::distance_from_source()
{
    std::cout << "Vertex\t\tDistance from Source\n";
    for (int i = 0; i < vertices.size(); ++i) {
        std::cout << vertices[i].id <<"\t\t" << vertices[i].distance <<"\n";
    }
}