#include "node.h"

/* By user created Nde type description. Only constructor. */
Node::Node(int data, Node *ptr = nullptr) {
    this->data = data;
    this->ptr = ptr;
}