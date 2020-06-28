#include <iostream>
using namespace std;


struct node {
    int key;
    node *left;
    node *right;
};

class btree {
public:
    btree();
    ~btree();

    void insert(int key);
    node *search(int key);
    void destroy();
    void inorderPrint();
    void postorderPrint();
    void preorderPrint();

private:
    void destroy(node *leaf);
    void insert(int key, node *leaf);
    node *search(int key, node *leaf);
    void inorderPrint(node *leaf);
    void postorderPrint(node *leaf);
    void preorderPrint(node *leaf);

    node *root;
};

btree::btree() {
    root = NULL;
}

btree::~btree() {
    destroy();
}

void btree::destroy(node *leaf) {
    if(leaf != NULL){
        destroy(leaf->left);
        destroy(leaf->right);
        delete leaf;
    }
}

void btree::insert(int key, node *leaf) {
    if(key < leaf->key){
        if(leaf->left != NULL) {
            insert(key, leaf->left);
        } else {
            leaf->left = new node;
            leaf->left->key = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }else if(key >= leaf->key) {
        if(leaf->right != NULL) {
            insert(key, leaf->right);
        } else {
            leaf->right = new node;
            leaf->right->key = key;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }
}

void btree::insert(int key) {
    if(root != NULL){
        insert(key, root);
    } else {
        root = new node;
        root->key = key;
        root->left = NULL;
        root->right = NULL;
    }
}

node *btree::search(int key, node *leaf) {
    if(leaf != NULL){
        if(key == leaf->key) {
            return leaf;
        }
        if(key < leaf->key){
            return search(key, leaf->left);
        } else {
            return search(key, leaf->right);
        }
    } else {
        return NULL;
    }
}

node *btree::search(int key) {
    return search(key, root);
}

void btree::destroy(){
    destroy(root);
}

void btree::inorderPrint() {
    inorderPrint(root);
    cout << "\n";
}

void btree::inorderPrint(node *leaf) {
    if(leaf != NULL){
        inorderPrint(leaf->left);
        cout << leaf->key << '\t';
        inorderPrint(leaf->right);
    }
}

void btree::postorderPrint(){
    postorderPrint(root);
    cout << "\n";
}

void btree::postorderPrint(node *leaf) {
    if(leaf != NULL){
        inorderPrint(leaf->left);
        inorderPrint(leaf->right);
        cout << leaf->key << '\t'; 
    }
}

void btree::preorderPrint() {
    preorderPrint(root);
    cout << "\n";
}

void btree::preorderPrint(node *leaf) {
    if(leaf != NULL){
        /* if(leaf->left == 0 && leaf->right == 0){
        cout << leaf->key << " ";
        } */
        cout << leaf->key << '\t';
        inorderPrint(leaf->left);
        inorderPrint(leaf->right);
    }
}
