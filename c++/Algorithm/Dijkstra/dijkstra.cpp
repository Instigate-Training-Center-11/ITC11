#include <iostream>
#include <list>
#include <stack>
#include <algorithm>

#define INF 10000

class Node {
    public:
        int ver;
        int weight;
};

class Graph {
    public:
        int vertex;
        std::list<Node> *List;

        Graph();
        Graph(int);
        void addEdge(int, int, int);
};

Graph::Graph() {
    vertex = 0;
}

Graph::Graph(int V) {
    vertex = V;
    List = new std::list<Node>[vertex];
}

void Graph::addEdge(int source, int ver, int weight) {
    Node newNode;
    newNode.ver = ver;
    newNode.weight = weight;
    List[source].push_back(newNode);
}

void dijkstra(Graph graph, int* dist, int source) {
    int vertex = graph.vertex;
    for (int i = 0; i < vertex; ++i) {
        dist[i] = INF;
    }

    dist[source] = 0;

    std::stack<int> S;
    std::list<int> L;

    for (int i = 0; i < vertex; ++i) {
        L.push_back(i);
    }

    while(!L.empty()) {
        std::list<int> :: iterator it;
        it = min_element(L.begin(), L.end());
        int i = *it;

        S.push(i);
        L.remove(i);

        std::list<Node> :: iterator in;
        for (in = graph.List[i].begin(); in != graph.List[i].end(); in++) {
            if ((dist[i]+(in->weight)) < dist[in->ver]) {
                dist[in->ver] = (dist[i]+(in->weight));
            }
        }
    }
}

int main() {
    Graph gh(5);
    int dist[5];
    gh.addEdge(0, 2, 4);
    gh.addEdge(0, 3, 8);
    gh.addEdge(1, 3, 5);
    gh.addEdge(1, 4, 6);
    gh.addEdge(2, 4, 4);
    gh.addEdge(0, 1, 3);
    gh.addEdge(0, 4, 1);
    gh.addEdge(1, 2, 2);
    gh.addEdge(2, 3, 3);
    gh.addEdge(3, 4, 2);
    int source = 0;
    std::cout << "Choose a starting point to calculate shortest destinations: ";
    std::cin >> source;
    dijkstra(gh, dist, source);

    std::cout << "\nShortest path from:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        if(i != source) {
            if (dist[i] != INF) {
                std::cout << source << " -> " << i << "   is  " << dist[i] << std::endl;
            } else {
                std::cout << source << " -> " << i << "   is  " << "infinity" << std::endl;
            }

        }
    }
    return 0;
}

