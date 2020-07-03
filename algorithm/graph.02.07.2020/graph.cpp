#include <iostream>
#include "graph.h"

Graph::Graph() {
}

Graph::Graph(unsigned int size) {
    addLists = new std::list<int> [size];
    this->size = size;
}
void Graph::AddEdge(int p1, int p2){
    addLists[p1].push_back(p2);
    addLists[p2].push_back(p1);
}

void Graph::Iterate (int data) {
    std::cout <<  data << " : ";
    for (auto it = addLists[data].begin(); it != addLists[data].end(); ++it){
        std::cout << *it << "-";
    }
    std::cout << "\n";
}

Graph::~Graph() {
    delete []  addLists;
}
