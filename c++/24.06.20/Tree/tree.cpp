#include <iostream>
#include "tree.h"

template <typename T>
Tree<T>::Tree() {
    root = NULL;
}

template <typename T>
Tree<T>::~Tree() {
    destroyTree();
}

template <typename T>
void Tree<T>::destroyTree(Node<T> *leaf) {
    if (NULL != leaf) {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete leaf;
    }
}

template <typename T>
void Tree<T>::insert(T value, Node<T> *leaf) {
    if (value < leaf->value) {
        if (NULL != leaf->left) {
            insert(value, leaf->left);
        } else {
            leaf->left = new Node<T>;
            leaf->left->value = value;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    } else if (value >= leaf->value) {
        if (NULL != leaf->right) {
            insert(value, leaf->right);
        } else {
            leaf->right = new Node<T>;
            leaf->right->value = value;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }
}

template <typename T>
void Tree<T>::insert(T value) {
    if (NULL != root) {
        insert(value, root);
    } else {
        root = new Node<T>;
        root->value = value;
        root->left = NULL;
        root->right = NULL;
    }
}

template <typename T>
Node<T> *Tree<T>::search(T value, Node<T> *leaf) {
    if (NULL != leaf) {
        if (value == leaf->value) {
            return leaf;
        }
        if (value < leaf->value) {
            return search(value, leaf->left);
        } else {
            return search(value, leaf->right);
        }
    } else {
        return 0;
    }
}

template <typename T>
Node<T> *Tree<T>::search(T value) {
    return search(value, root);
}

template <typename T>
void Tree<T>::destroyTree() {
    destroyTree(root);
}

template <typename T>
void Tree<T>::inorderPrint(Node<T> *leaf){
    if (NULL != leaf){
        inorderPrint(leaf->left);
        std::cout << leaf->value << " ";
    }
}

template <typename T>
void Tree<T>::inorderPrint(){
        inorderPrint(root);
        std::cout << "\n";
}

template <typename T>
void Tree<T>::levelOrderPrint() {
    levelOrderPrint(root);
    std::cout << "\n";
}

template <typename T>
void Tree<T>::levelOrderPrint(Node<T>* leaf) {
    if(NULL != leaf){
        std::cout << leaf->value << " ";
        inorderPrint(leaf->left);
        inorderPrint(leaf->right);
    }
}

/*template <typename T>
void Tree<T>::display() {
    
}*/
