#include "graph.hpp"

Graph::Graph(int real_size, int print_size) {
    my_city = new std::pair<std::list<int>, std::string> [real_size];
    this->real_size = real_size;
    this->print_size = print_size;
}

Graph::~Graph() {
    delete [] my_city;
}

void Graph::add_city(int id, std::string city_name) {
    my_city[id].second = city_name;
    ++print_size;
}

void Graph::add_edge(int src, int dst) {
    my_city[src].first.push_back(dst);
    my_city[dst].first.push_back(src);
}

void Graph::print_edges(int id) {
    std::cout << my_city[id].second << "---> ";
    for (auto& edges : my_city[id].first) {
        std::cout << edges << " ";
    }
    std::cout << std::endl;
}

void Graph::print_graph() {
    for (int id = 0; id < print_size; ++id) {
        std::cout << "ID: " << id << " ";
        std::cout << my_city[id].second << std::endl;
    }
    std::cout << std::endl;
}