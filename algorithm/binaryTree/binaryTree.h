#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include <iostream>
#include <vector>

struct Node {
    int value;
    Node *right;
    Node *left;

    Node(int value) {
        this->value = value;
        this->right = NULL;
        this->left = NULL;
    }
};

class BinaryTree {
    Node *root;
    int countNodes = 1;
    void insert(Node *root, int value);
    bool remove(Node *parent, Node *current, int value);
    Node* nextLarger(Node *node);
    Node* findNodeWithValue(int value);
    void print(Node *node);
    void storeBSTNodes(Node *root, std::vector<Node*> &nodes);
    Node* buildTreeUtil(std::vector<Node*> &nodes, int start,int end);

public:

    /* The function gets the number n and returns n-th max value in the tree */
    int getMaxTime(int n);
    /* balancing a tree */
    void buildTree(Node *root);
    /* wrapper function for insert */
    void insert(int value);
    /* wrapper function for remove */
    bool remove(int value);
    Node* findMax();
    Node* getRoot();
    void printTree();
    int getCountNodes(void);
    BinaryTree(void);
    ~BinaryTree(void);

};

#endif