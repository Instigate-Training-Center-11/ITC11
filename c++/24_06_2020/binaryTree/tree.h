#ifndef _TREE_H_
#define _TREE_H_

template<typename Type>

class BinaryTree {

    struct Node {
        Node* Left;
        Node* Right;
        Type data;
    };

    Node* Root;
    public:

    BinaryTree();
    void inOrder(Node* order);
    void postOrder(Node* order);
    void preOrder(Node* order);
    void display (int);
    bool empty(void);
    void insert(Type nodeValue);
    ~BinaryTree();

};


#include "tree.cpp"
#endif