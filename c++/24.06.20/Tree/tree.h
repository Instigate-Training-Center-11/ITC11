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
        void inorderPrint();
        void levelOrderPrint();
};

#endif
