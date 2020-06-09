#include "node.h"

/* By user created Nde type description. Only constructor. */
template <typename T>
Node<T>::Node(T data, Node *ptr) {
    this->data = data;
    this->ptr = ptr;
}