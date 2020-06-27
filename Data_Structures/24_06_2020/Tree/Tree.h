#ifndef TREE_H
#define TREE_H

/* This is header file describing user-defined type Tree. */
template <typename T>
struct Node {
    T data;
    Node *left;
    Node *right;
};

template <typename T>
class Tree {
    private:
        Node<T> *root;
        Node<T> *get_element(Node<T>*, T);
        Node<T> *remove(Node<T>*, T);
        void insert(Node<T>*, T);
        void destroy(Node<T>*);
        void in_order_print(Node<T>*);
        void pre_order_print(Node<T>*);
        void post_order_print(Node<T>*);
        void level_order_print(Node<T>*);
        bool isLeafNode(Node<T>*);
        Node<T> *min(Node<T>*);
    public:
        Tree();
        ~Tree();
        void insert(T);
        void destroy();
        void display();
        Node<T> *remove(T);
        Node<T> *get_element(T);
};

#endif