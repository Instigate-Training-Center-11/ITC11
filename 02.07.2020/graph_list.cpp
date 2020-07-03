#include <iostream>

/* class for List Node */
class Node
{
    public:
        int data;
        Node *next;
};

/* class for List */
class List
{
    public:
        Node *head;
};

/* class for Graph */
class Graph
{
    public:
        int v;
        List* arr;
};

Node *newNode(int);
Graph *createGraph(int);
void addEdge(Graph*,int,int);
void print(Graph*);

int main()
{
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    /* create a star shaped graph like this: 

                2
                .
               . .
        1 . . . . . . . 3
             .     .
            .   .   .
           . .     . .
          0           4
    */

    addEdge(graph,0,2);
    addEdge(graph,0,3);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,4);

    print(graph);

    return 0;
}

/* create a new node */
Node* newNode(int data)
{
    Node* nn = new Node;
    nn->data = data;
    nn->next = NULL;
    return nn;
}

/* function to create a graph of v vertices */
Graph* createGraph(int v)
{
    Graph *graph = new Graph;
    graph->v = v;
    graph->arr = new List[v];

    /* initialize graph elements with NULL */
    for (int i = 0; i < v; ++i)
    {
        graph->arr[i].head = NULL;
    }

    return graph;
}

/* function to add an edge to Graph */
void addEdge(Graph* graph, int mainV, int nextV)
{
    /* add an edge from a vetrex (mainV) to another vertex (nextV) */
    Node* edge = newNode(nextV);
    edge->next = graph->arr[mainV].head;
    graph->arr[mainV].head = edge;

    edge = newNode(mainV);
    edge->next = graph->arr[nextV].head;
    graph->arr[nextV].head = edge;
}

/* function to desplay the graph */
void print(Graph* graph)
{
    for(int i = 0; i < graph->v; ++i)
    {
        Node *vertex = graph->arr[i].head;
        std::cout << "vertex " << i << " --> ";

        while(vertex != NULL)
        {
            std::cout << vertex->data << "  ";
            vertex = vertex->next;
        }
        std::cout << std::endl;
    }
}