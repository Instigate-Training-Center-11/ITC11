#ifndef _BELLMANFORD_H_
#define _BELLMANFORD_H_
#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<map>
typedef std::pair<int,int> PII;

class Graph {

private:

    int nodescount;
    std::list<int> *cityslist;
    std::vector<bool> visited;
    std::stack<int> stackorder;
    std::map<PII,int> edgeweight;

public:

    Graph();
    Graph (int nodescount);
    ~Graph ();
    /* adds weight to the rib */
    void AddEdgeWeight (int src, int dst, int weight);
    /* creates ribs src->dist */
    void AddEdge (int src, int dst);
    /* Only after all the outgoing edges are visited push the source node in the stack */
    void TopologicalSort (int src);
    /* calculate all possible short roads from source */
    void BellmanFord (int sourcenode);

};

#endif