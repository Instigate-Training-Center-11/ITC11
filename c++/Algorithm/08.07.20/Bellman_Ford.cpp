#include <iostream>

const int INF = 1000000;

class Edge {
    public:
        int startVertex;
        int endVertex;
        int weight;
};

class Graph {
    public:
        int V;
        int E;
        Edge* edge;
};

class Graph* create(int V, int E) {
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void show(int *dist, int size) {
    std::cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < size; ++i) {
        std::cout << i << "      " << dist[i] << std::endl;
    }
}

void BellmanFord(Graph* graph, int startVertex) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[startVertex] = 0;
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int starVertex = graph->edge[j].startVertex;
            int endVertex = graph->edge[j].endVertex;
            int weight = graph->edge[j].weight;
            if (dist[startVertex] != INF && dist[startVertex] + weight < dist[endVertex]) {
                dist[endVertex] = dist[startVertex] + weight;
            }
        }
    }

    for (int i = 0; i < E; i++) {
        int startVertex = graph->edge[i].startVertex;
        int endVertex = graph->edge[i].endVertex;
        int weight = graph->edge[i].weight;
        if (dist[startVertex] != INF && dist[startVertex] + weight < dist[endVertex]) {
            std::cout << "Graph contains negative weight cycle" << std::endl;
            return;
        }
    }
    show(dist, V);
}

int main() {

    int V = 6;
    int E = 8;

    Graph* graph = create(V, E);

    graph->edge[0].startVertex = 0;
    graph->edge[0].endVertex = 1;
    graph->edge[0].weight = 5;

    graph->edge[1].startVertex = 0;
    graph->edge[1].endVertex = 2;
    graph->edge[1].weight = -5;

    graph->edge[2].startVertex = 1;
    graph->edge[2].endVertex = 2;
    graph->edge[2].weight = 4;

    graph->edge[3].startVertex = 1;
    graph->edge[3].endVertex = 3;
    graph->edge[3].weight = 2;

    graph->edge[4].startVertex = 3;
    graph->edge[4].endVertex = 4;
    graph->edge[4].weight = -3;

    graph->edge[5].startVertex = 3;
    graph->edge[5].endVertex = 2;
    graph->edge[5].weight = 5;

    BellmanFord(graph, 0);
    return 0;
}

