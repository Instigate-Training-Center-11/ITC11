#ifndef TREE_H
#define TREE_H

template <typename T>
class Node {
    public:
        T value;
        Node *left;
        Node *right;
};

template <typename T>
class Tree {
    private:
        Node<T> *root;
        void destroyTree(Node<T> *leaf);
        void insert(T value, Node<T> *leaf);
        Node<T> *search(T value, Node<T> *leaf);
        void inorderPrint(Node<T>* leaf);
        void postorderPrint(Node<T>* leaf);
        void preorderPrint(Node<T>* leaf);
        void levelOrderPrint(Node<T>* leaf);
    public:
        /*constructor*/
        Tree();
        /*destructor*/
        ~Tree();
        /*insert new element*/
        void insert(T value);
        /*delete tree*/
        void destroyTree();
        /*searc element */
        Node<T> *search(T value);
        /*get element by value*/
        Node<T> *getNodeByValue(Node<T> *leaf, T value);
        /*remove element*/
        Node<T> *removeNodeByPtr(Node<T> *leaf, T value);
        /*find min value*/
        Node<T>* findMinValue(Node<T>*);
        void inorderPrint();
        void postorderPrint();
        void preorderPrint();
        void levelOrderPrint();
};

#endif
