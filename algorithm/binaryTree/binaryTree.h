#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include <iostream>
struct Node {
    int value;
    Node *right;
    Node *left;

    Node(int value) {
        this->value = value;
        this->right = nullptr;
        this->left = nullptr;
    }
};
class BinaryTree {
    int LeftHeight = 0;
    int RightHeight = 0;
    Node *root;
    void insert(Node *root, int value);
    bool remove(Node *parent, Node *current, int value);
    Node* nextLarger(Node *node);
    Node* findNodeWithValue(int value);
    void print(Node *node);
public:
    /* The function gets the number n and returns n-th max value in the tree */
    int getMaxTime(int n);
    int getLeftHeight(void);
    int getRightHeight(void);
    /* wrapper function for insert */
    void insert(int value);
    /* wrapper function for remove */
    bool remove(int value);
    Node* findMax();
    Node* getRoot();
    void printTree();
};

#endif