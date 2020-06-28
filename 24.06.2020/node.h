#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
    public:
        T value;
        Node<T> *right;
        Node<T> *left;

        Node<T>(T);
        ~Node<T>();
};

#endif