#include <iostream>
#include <cstdlib>

/*class for list node*/
class Node {
    public:
        int value;
        Node* next;
};

/*class List*/
class List {
    public:
        Node *head;
};

/*class Graph*/
class Graph {
    private:
        int vertex;
        List* array;
    public:
        Graph(int vertex) {
            this->vertex = vertex;
            array = new List [vertex];
            for (int i = 0; i < vertex; ++i)
                array[i].head = NULL;
        }

        /*creating new List Node*/
        Node* newListNode(int value) {
            Node* newNode = new Node;
            newNode->value = value;
            newNode->next = NULL;
            return newNode;
        }

        /*Adding Edge to Graph*/
        void addEdge(int src, int value) {
            Node* newNode = newListNode(value);
            newNode->next = array[src].head;
            array[src].head = newNode;
            newNode = newListNode(src);
            newNode->next = array[value].head;
            array[value].head = newNode;
        }

        /*Print the graph*/
        void printGraph() {
            int ver;
            for (ver = 0; ver < vertex; ++ver) {
                Node* curr = array[ver].head;
                std::cout << "\n Adjacency list of vertexertex " << ver << "\n head ";
                while (curr) {
                    std::cout << "-> " << curr->value;
                    curr = curr->next;
                }
                std::cout << std::endl;
            }
        }
};

/*Main*/
int main() {
    Graph gh(5);
    gh.addEdge(0, 2);
    gh.addEdge(0, 3);
    gh.addEdge(1, 3);
    gh.addEdge(1, 4);
    gh.addEdge(2, 4);
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);
    gh.printGraph();
    return 0;
}

