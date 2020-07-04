#include <iostream>
#include <list>
#include <stack>
#include <algorithm>

#define INF 9999

/* created class for nodes */
class Node
{
    public:
        int dest;   
        int weight;
};

/* created calss for graph */
class Graph
{
    public:
        int n;
        std::list<Node> *List;

        Graph();
        Graph(int);
        void addEdge(int, int, int);
};

/* default constructor */
Graph::Graph()
{
    n = 0;
}

/* parametrized constructor */
Graph::Graph(int nodeCount)
{
    n = nodeCount;
    List = new std::list<Node>[n];
}

/* member function to add edges */
void Graph::addEdge(int source, int dest, int weight)
{
    Node newNode;
    newNode.dest = dest;
    newNode.weight = weight;
    List[source].push_back(newNode);
}

/* function for Dijkstra algorithm to find shortest destination through vertices */
void DijkstraAlgorithm(Graph graph, int* dist, int source)
{
    int n = graph.n;
    for (int v = 0; v < n; ++v)
    {
        /* set distance as infinity */
        dist[v] = INF;
    }

    /* set distance of source 0*/
    dist[source] = 0;

    /* create an empty list and an empty stack */
    std::stack<int> S;
    std::list<int> L;

    for (int v = 0; v < n; ++v)
    {
        L.push_back(v);
    }

    while(!L.empty())
    {
        std::list<int> :: iterator il;
        il = min_element(L.begin(), L.end());
        int v = *il;

        S.push(v);
        L.remove(v);

        std::list<Node> :: iterator in;
        for (in = graph.List[v].begin(); in != graph.List[v].end(); in++)
        {
            if ((dist[v]+(in->weight)) < dist[in->dest])
            {
                dist[in->dest] = (dist[v]+(in->weight));
            }
        }
    }
}

int checkType(int);

int main()
{
    int countV = 9;
    Graph graph(countV);
    int dist[countV];

    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 3, 4);
    graph.addEdge(1, 0, 3);
    graph.addEdge(1, 4, 1);
    graph.addEdge(1, 2, 5);
    graph.addEdge(2, 1, 3);
    graph.addEdge(2, 5, 6);
    graph.addEdge(3, 0, 1);
    graph.addEdge(3, 4, 5);
    graph.addEdge(3, 6, 7);
    graph.addEdge(4, 5, 1);
    graph.addEdge(5, 4, 2);
    graph.addEdge(5, 8, 1);
    graph.addEdge(6, 3, 2);
    graph.addEdge(6, 7, 1);
    graph.addEdge(7, 4, 2);
    graph.addEdge(7, 6, 2);
    graph.addEdge(7, 8, 2);
    graph.addEdge(8, 5, 4);

     /* created graph
                     1                                5
        ..............................>     ...........................>
      [0]                               [1]                             [2]
        <.............................     <...........................  
     .               3                   .               3             .
     .                                   .                             .
     .                                   .                             .
    4.                                  1.                            6.
     .                                   .                             .
     .                                   .                             .
     v               5                   v               1             v
       ------------------------------>     ---------------------------->
      [3]                               [4]                             [5]
                                           <----------------------------  
     . ^                                 ^               2           ^ .
     . .                                 .                           . .
     . .                                 .                           . .
    7. . 2                               .  2                       4. .1
     . .                                 .                           . .
     . .                                 .                           . .
     v .             1                   .               2           . v
       ------------------------------>     ---------------------------->
      [6]                               [7]                             [8]
        <----------------------------  
                     2    
     */
    std::cout << "      ****************** Graph example ******************" <<std::endl << std::endl;
    std::cout << "      {0}      1->     <-3     {1}     5->     <-3     {2}" << std::endl;
    std::cout << "\v" << std::endl;
    std::cout << "       4                        1                       6" << std::endl;
    std::cout << "       |                        |                       |" << std::endl;
    std::cout << "       v                        v                       v" << std::endl;
    std::cout << std::endl;
    std::cout << "       ^                                                 " << std::endl;
    std::cout << "       |                                                 " << std::endl;
    std::cout << "       1                                                 " << std::endl;
    std::cout << "\v" << std::endl;
    std::cout << "      {3}      5->             {4}     1->     <-2     {5}" << std::endl;
    std::cout << std::endl;
    std::cout << "       7                                                1" << std::endl;
    std::cout << "       |                                                |" << std::endl;
    std::cout << "       v                                                v" << std::endl;
    std::cout << std::endl;
    std::cout << "       ^                        ^                       ^" << std::endl;
    std::cout << "       |                        |                       |" << std::endl;
    std::cout << "       2                        2                       4" << std::endl;
    std::cout << "\v" << std::endl;
    std::cout << "      {6}     1->      <-2     {7}     2->             {8}" << std::endl;
    std::cout << std::endl;
 
    int source = 0;
    std::cout << "Please choose a starting point to calculate shortest destinations: ";
    std::cin >> source;
    source = checkType(source);

    DijkstraAlgorithm(graph, dist, source);

    std::cout << "\nShortest path from:" << std::endl;
    for (int i = 0; i < countV; ++i)
    {
        if(i != source)
        {
            if (dist[i] != INF)
            {
                std::cout << source << " --> " << i << "   is  " << dist[i] << std::endl;
            }
            else
            {
                std::cout << source << " --> " << i << "   is  " << "infinity" << std::endl;
            }
            
        }
    }

    return 0;
}

/* check  whether input number is integer or not */
int checkType(int input)
{
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();

        std::cout << "\nPlease enter integer type data: " << std::endl;
        std::cin >> input;
    }

    return input;
}
