#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <list>
#include <vector>


class Graph {

    std::list<int> *addLists;
    unsigned int size;
public:

    Graph();
    Graph(unsigned int);
    ~Graph();

    void AddEdge (int p1,int p2);
    void Iterate (int data);

};


#endif