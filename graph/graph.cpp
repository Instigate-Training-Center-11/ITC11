#include <iostream>
#include <vector>
#include "graph.h"

#define MAX 1000000


Graph::Node::Node(const int val, const int weight): val(val), weight(weight){}

// Function to create new node of Adjacency List
Graph::Node* Graph::getAdjListNode(const int last, const int weight, Node* head) {
    Node* newNode = new Node(last, weight);
    newNode->next = head;

    return newNode;
}

// Constructor
Graph::Graph(const Edge edges[], const int n, const int m) {
    // allocate memory
    head = new Node*[m]();
    nodeNumber = m;

    // initialize head pointer for all vertices
    for (int i = 0; i < m; ++i) {
        head[i] = nullptr;
    }

    // add edges to the graph
    for (int i = 0; i < n; ++i) {
        int first = edges[i].first;
        int last = edges[i].last;
        int weight = edges[i].weight;
        Node* newNode = getAdjListNode(last, weight, head[first]);
        head[first] = newNode;
    }
}

// destructor
Graph::~Graph() {
    for (int i = 0; i < nodeNumber; ++i) {
        delete[] head[i];
    }

    delete[] head;
}

//print graph
void Graph::printList() {

    Node * tmp;

    for (int i = 0; i < nodeNumber; ++i) {
        tmp = head[i];
        while (tmp != nullptr) {
            std::cout << "(" << i << ", "
            << tmp->val << ", " << tmp->weight << ")";
            tmp = tmp->next;
            if(nullptr != tmp) {
                std::cout << " −> ";
            }
        }
        std::cout << std::endl;
    }
}

bool Graph::check(int &node, int &m) {
    if(m == node) {
        return false;
    }
    else if(m < node) {
        int tmp = node;
        node = m;
        m = tmp;
    }

    return true;
}

int Graph::minWay(int node, int m) {
    //if node = m return 0
    if(!check(node, m)) {
        return 0;
    }

    //vector contain node from which came and way
    std::vector<std::pair<int, int>> vec;

    //in the first all node initialize -1 and all way initialize MAX
    for(int i = 0; i < nodeNumber; ++i) {
        vec.push_back({-1, MAX});
    }

    //where did the way begin
    vec[node].first = 0;
    vec[node].second = 0;

    int minWay = 0; //minimum way from node to m
    int i = node; //start
    int count = 0; //the number of nodes that passed
    int indexes[nodeNumber] = {-1, -1, -1, -1, -1, -1, -1, -1,-1}; // array of nodes that passed
    int prev = -1; //prevuse index of passed node

    //continues while all nodes do not passed
    while(count != nodeNumber) {
        indexes[i] = i;
        Node* tmp = head[i];//first node of graph
        int minIndex = -1, min = MAX;

        //continues while all neighborhood nodes do not comparing
        while(tmp != nullptr) {
            //if node way greater of new way , then changes way
            if(vec[tmp->val].second > tmp->weight + vec[i].second) {
                vec[tmp->val].second = tmp->weight + vec[i].second;
                vec[tmp->val].first = i;
            }

            //find minium neighborhood node
            if(min > tmp->weight && indexes[tmp->val] == -1) {
                min = tmp->weight;
                minIndex = tmp->val;
            }
            tmp = tmp->next;
        }

        ++count;
        if(min != MAX && prev != i) {
            i = minIndex;//change current node
        } else if(prev == i) {
            for(int j = 0; j < vec.size(); ++j) {
                if(vec[j].first == prev) {
                    i = j; //change current node
                }
            }
            continue;
        }
        prev = i;
    }

    int it = m;
    std::cout << std::endl << "Start from: " << std::endl;
    while (it!=node) {
        if(head[vec[it].first]->val == it) {
            std::cout << "node: " << it << " way: " <<  head[vec[it].first]->weight << std::endl;
            minWay += head[vec[it].first]->weight;
            it = vec[it].first;
        } else {
            head[vec[it].first] = head[vec[it].first]->next;
        }
    }

    return minWay;
}