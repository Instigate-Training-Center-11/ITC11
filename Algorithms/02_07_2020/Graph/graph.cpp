#include <iostream>
#include <list>
#include <iterator>

class Graph {
    public:
    void printLiat(std::list<int> adgList[], int vertex) {
        for(int i = 0; i < vertex; ++i) {
            std::cout << i << " ->>> ";
            std::list<int>::iterator it;
            for(it = adgList[i].begin(); it != adgList[i].end(); ++it) {
                std::cout << *it << " ";
            }

            std::cout << "\n";
        }
    }

    void addEdge(std::list<int> adgList[], int u, int v) {
        adgList[u].push_back(v);
        adgList[v].push_back(u);
    }
};

int main() {
    int vertex = 6;
    std::list<int> adgList[vertex];
    Graph graph;

    graph.addEdge(adgList, 0, 4);
    graph.addEdge(adgList, 0, 3);
    graph.addEdge(adgList, 1, 2);
    graph.addEdge(adgList, 1, 4);
    graph.addEdge(adgList, 1, 5);
    graph.addEdge(adgList, 2, 3);
    graph.addEdge(adgList, 2, 5);
    graph.addEdge(adgList, 5, 3);
    graph.addEdge(adgList, 5, 4);

    /* Display graph */
    graph.printLiat(adgList, vertex);
}