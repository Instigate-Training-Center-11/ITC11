#include "graph.h"

int main() {

    Graph carentGraph(10);

    for (unsigned int i = 0; i < 10; ++i) {
        carentGraph.AddEdge(0,i);
    }

    for (unsigned int i = 0; i < 10; ++i) {
        carentGraph.Iterate(i);
    }

    return 0;
}
