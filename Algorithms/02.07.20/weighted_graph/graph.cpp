#include "graph.hpp"

void Graph::add_city(std::string city_name, std::string dst_name, int weight) {
    my_city[city_name].edge.push_back(dst_name);
    my_city[city_name].weight.push_back(weight);
    my_city[dst_name].edge.push_back(city_name);
    my_city[dst_name].weight.push_back(weight);
}


void Graph::print (std::string name) {
    std::cout << "From " << name << ":\t";
    auto temp = my_city[name];
    int size = temp.edge.size();
    for (int i = 0; i < size; ++i) {
        std::cout << temp.edge[i] << "->" << temp.weight[i] << "km\t";
    }
    std::cout << std::endl;
}