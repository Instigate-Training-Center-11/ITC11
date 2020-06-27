#include <iostream>

#include "node.h"

template <typename T>
Node<T>::Node(T value)
{
    this->value = value;
    this->right = NULL;
    this->left = NULL;
}