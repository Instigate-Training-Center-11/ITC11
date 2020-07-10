#include "graph.hpp"

void Graph::add_city(std::string city_name, std::string dst_name, int weight) {
    my_city[city_name].edges.push_back({dst_name, weight});
    my_city[dst_name].edges.push_back({city_name, weight});
}


void Graph::print (std::string name) {
    std::cout << "From " << name << ":\t";
    auto temp = my_city[name];
    int size = temp.edges.size();
    for (int i = 0; i < size; ++i) {
        std::cout << "[" << temp.edges[i].first << " ->\t" << temp.edges[i].second << "km]\t";
    }
    std::cout << std::endl;
}

void Graph::dijkstras_path(std::string source, std::string dst) {
    std::map<std::string, int> distance;
    std::set<std::pair<int, std::string>> set_edge;

    /* adding infinity value for all edges */
    for (auto& i : my_city) {
        distance[i.first] = 99999999;
    }

    distance[source] = 0;
    set_edge.insert({0, source});

    while (!set_edge.empty()) {
        std::pair<int, std::string> top = *set_edge.begin();
        set_edge.erase(set_edge.begin());

        std::string source = top.second;
        for(auto& it : my_city[source].edges) {
                std::string current_edge = it.first;
                int current_weight = it.second;

            if (distance[current_edge] > current_weight + distance[source]) {
                distance[current_edge] = current_weight + distance[source];
                set_edge.insert({distance[current_edge], current_edge});
            }
        }
    }

    std::cout << "\nSource [" << source << "] ---> dstination [" << dst << "] : " << distance[dst] << "km" << std::endl;
}