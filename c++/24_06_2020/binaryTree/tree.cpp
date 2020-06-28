#include <iostream>
#include "tree.h"

template<typename Type>
BinaryTree<Type>::BinaryTree() {
    Root = nullptr;
}

template <typename Type>
bool BinaryTree<Type>::empty() {
    return(this->Root == nullptr);
}

template <typename Type>
void BinaryTree<Type>::insert(Type nodevalue) {
    Node* newNode = new  Node();
    Node* parent;
    newNode->data = nodevalue;
    newNode->Left = nullptr;
    newNode->Right = nullptr;
    if (empty()) {
        Root = newNode;
    } else {
        Node* temp = Root;
        while (temp != nullptr) {
            parent = temp;
            if (temp->data < nodevalue) {
                temp = temp->Right;
            } else {
                temp = temp->Left;
            }
            if (nodevalue > parent->data) {
                parent->Left = newNode;
                std::cout << "  " << newNode->data << "     ";
            } else {
                parent->Right = newNode;
                std::cout << "  " << newNode->data << "     ";
            }
        }
    }
}

template<typename Type>
void BinaryTree<Type>::display(int index) {
    switch(index) {
    case 0:
        inOrder(Root);
        break;
    case 1:
        postOrder(Root);
        break;
    case 2:
        preOrder(Root);
        break;
    default:
        break;
    }
}

template<typename Type>
void BinaryTree<Type>::inOrder(Node* order) {
    std::cout << "Call function inOrder\n";
}

template<typename Type>
void BinaryTree<Type>::preOrder(Node* order) {
    std::cout << "Call function preOrder\n";
}

template<typename Type>
void BinaryTree<Type>::postOrder(Node* order) {
    std::cout << "Call function postOrder\n";
}

template<typename Type>
BinaryTree<Type>::~BinaryTree() {

}
