#ifndef _NODE_HPP
#define _NODE_HPP

template<typename Type>
class Node {
public:
    Node* next;
    Type value;

    /* Constructor with default arguments for class Node */
    Node(Type value = Type(), Node* node = nullptr) : value(value), next(node) {
    }
};

#endif