#ifndef NODE_HPP
#define NODE_HPP

class Node {
    public:
    Node* next;
    int value;

    /* Constructor with default arguments for class Node */
    Node(int value = 0, Node* node = nullptr) : value(value), next(node) {

    }
};

#endif