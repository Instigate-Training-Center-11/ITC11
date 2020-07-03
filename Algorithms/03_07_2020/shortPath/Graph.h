#ifndef GRAPH_H
#define GRAPH_H

#include <list>

#define INF 999999999

typedef std::pair<int, int> myPair;

class Graph {
    private:
        int vertex;
        std::list<myPair> *adgList;
    public:
        Graph(int);
        void addEdge(int, int, int);
        void shortPath(int);
};

#endif