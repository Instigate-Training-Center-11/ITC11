#ifndef NODE_H
#define NODE_H

    /*
    This is an node.h file that represents Node
    the type that the user created.
    */
    class Node {
        public:
            int data;
            Node *ptr;
            Node(int data, Node *ptr);
    };

#endif