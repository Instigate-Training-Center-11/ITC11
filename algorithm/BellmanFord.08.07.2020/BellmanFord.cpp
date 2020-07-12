#include "BellmanFord.h"

Graph::Graph() {
}

Graph::Graph (int nodescount) {
    cityslist = new std::list<int> [nodescount];
    visited.resize(nodescount, false);
    this->nodescount = nodescount;
}

Graph::~Graph () {
    delete [] cityslist;
}

void Graph::AddEdgeWeight (int src, int dst, int weight) {
    edgeweight.emplace(std::make_pair(src,dst),weight);
}

void Graph::AddEdge (int src, int dst) {
    cityslist[src].push_back(dst);
}

void Graph::TopologicalSort (int src) {
    visited[src] = true;
    for (auto& itr : cityslist[src]) {
        if (!visited[itr]) {
            TopologicalSort(itr);
        }
    }

    stackorder.push(src);
}

void Graph::BellmanFord (int sourcenode) {

    for (int i = 0; i < nodescount; i++) {
        if (!visited[i]) {
            TopologicalSort(i);
        }
    }

    std::vector<int> dist(nodescount, 999999999);
    dist[sourcenode] = 0;
    while (!stackorder.empty()) {
        int u = stackorder.top();
        stackorder.pop();
        for (auto& v: cityslist[u]) {
            int weight = edgeweight.find(std::make_pair(u,v))->second;
            if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
            }
        }
    }
    std::cout << "Shortest Path from source node:" << sourcenode << "\n\n";
    for (int i = 0; i < nodescount; i++) {
        std::cout << "(" << sourcenode;
        switch(i) {
            case 0:
                std::cout << ") -> Seattle(" << i << ") : " << dist[i] << " km" <<std:: endl;
                break;
            case 1:
                std::cout << ") -> SanFrancisco(" << i << ") : " << dist[i] << " km" <<std:: endl;
                break;
            case 2:
                std::cout << ") -> Denver(" << i << ") : " << dist[i] << " km" <<std:: endl;
                break;
            case 3:
                std::cout << ") -> LasVegas(" << i << ") : " << dist[i] << " km" <<std:: endl;
                break;
            case 4:
                std::cout <<  ") -> LosAngeles(" << i << ") : " << dist[i] << " km" <<std:: endl;
                break;
            case 5:
                std::cout << ") -> Phoenix(" << i << ") : " << dist[i] << " km" <<std:: endl;
                break;
            case 6:
                std::cout << ") -> Miami(" << i << ") : " << dist[i] << " km" <<std:: endl;
                break;
        }
    }
}


