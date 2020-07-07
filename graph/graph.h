#ifndef LIST_H
#define LIST_H

struct Edge {
    int first, last, weight, prev;
};

class Graph {
private:
    int nodeNumber;	// number of nodes in the graph

public:
    struct Node {
        int val; //prev node
        int way;
        int weight;
        Node* next;
        Node();
        Node(int val, int weight);
    };

    // Function to create new node of Adjacency List
    Node* getAdjListNode(const int last, const int weight, Node* head);

    // An array of pointers to Node to represent, adjacency list
    Node **head;

    //print graph
    void printList();

    //calculate minimum way
    int minWay(int node, int m);

    //check node == m
    bool check(int &node, int &m);
    
    // Constructor
    Graph(const Edge edges[], const int n, const int m);

    // destructor
    ~Graph();

    // int mino(int node, std::vector<int> index, int i);
};

#endif