#ifndef TREE_H
#define TREE_H

#include "node.h"
template <typename T>
class Tree
{
    private:
        Node<T> *root;

        void insert(Node<T>*, T);
        bool removeNodeByPtr(Node<T>*, Node<T>*, T);
        Node<T>* getNodeByValue(T);
        int height(Node<T>*);
        void printLevel(Node<T>*, int);
        void levelorderPrint(Node<T>*);
        void inorderPrint(Node<T>*);
        void postorderPrint(Node<T>*);
        void preorderPrint(Node<T>*);

    public:
        void insert(T);
        bool remove(T);
        void print();
};
#endif