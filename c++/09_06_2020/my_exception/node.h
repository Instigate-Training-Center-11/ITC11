#ifndef NODE_H
#define NODE_H

    /* This is an node.h file that represents Node the type that the user created. */
    template <typename T>
    class Node {
        public:
            T data;
            Node *ptr;
            Node(T data, Node *ptr);
    };

#endif