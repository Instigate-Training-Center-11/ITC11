#include <iostream>
#include <queue>
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
        return NULL;
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
Node<T> *Tree<T>::getNodeByValue(Node<T> *leaf, T value) {
    if(leaf == NULL) {
        return leaf;
    } else if (value > leaf->value) {
        return getNodeByValue(leaf->right, value);
    } else {
        return getNodeByValue(leaf->left, value);
    }
}

template <typename T>
Node<T>* Tree<T>::findMinValue(Node<T>* leaf) {
    Node<T> *current = leaf;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

template <typename T>
Node<T>* Tree<T>::removeNodeByPtr(Node<T> *leaf, T value) {
    if (leaf == NULL) {
        return leaf;
    } else if (value < leaf->value) {
        leaf->left = removeNodeByPtr(leaf->left, value);
    } else if (value > root->value) {
        leaf->right = removeNodeByPtr(leaf->right, value);
    } else {
        /*no child*/
        if (leaf->left == NULL && leaf->right == NULL) {
            delete leaf;
            leaf = NULL;
            return NULL;
        } /*one child*/
        else if (leaf->left == NULL) {
            Node<T> *tmp = leaf;
            leaf = leaf->right;
            delete tmp;
            return leaf;
        } else if (leaf->right == NULL) {
            Node<T> *tmp = leaf;
            leaf = leaf->left;
            delete tmp;
            return leaf;
        } /*two child*/
        else {
            Node<T> *tmp = findMinValue(leaf->right);
            leaf->value = tmp->value;
            leaf->right = removeNodeByPtr(leaf->right, tmp->value);
        }
    }
    return leaf;
}

template <typename T>
void Tree<T>::inorderPrint(){
    inorderPrint(root);
    std::cout << "\n";
}

template <typename T>
void Tree<T>::inorderPrint(Node<T> *leaf){
    if (NULL != leaf){
        inorderPrint(leaf->left);
        std::cout << leaf->value << " ";
        inorderPrint(leaf->right);
    }
}

template <typename T>
void Tree<T>::preorderPrint(){
        preorderPrint(root);
        std::cout << "\n";
}

template <typename T>
void Tree<T>::preorderPrint(Node<T>* leaf) {
    if(NULL != leaf){
        std::cout << leaf->value << " ";
        inorderPrint(leaf->left);
        inorderPrint(leaf->right);
    }
}

template <typename T>
void Tree<T>::postorderPrint(){
    postorderPrint(root);
    std::cout << "\n";
}

template <typename T>
void Tree<T>::postorderPrint(Node<T>* leaf) {
    if(NULL != leaf){
        inorderPrint(leaf->left);
        inorderPrint(leaf->right);
        std::cout << leaf->value << " ";
    }
}

template <typename T>
void Tree<T>::levelOrderPrint() {
    if (root != NULL) {
        std::queue<Node<T>*> q;
        q.push(root);
        while (!q.empty()) {
            Node<T>* current = q.front();
            std::cout << current->value << " ";
            q.pop();
            if (current->left) {
                q.push(current->left);
            }

            if (current->right) {
                q.push(current->right);
            }
        }
        std::cout << std::endl;
    }
}
