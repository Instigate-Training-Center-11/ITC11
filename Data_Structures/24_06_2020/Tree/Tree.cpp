#include <iostream>
#include <queue>
#include "Tree.h"

/* Default constructor. */
template <typename T>
Tree<T>::Tree() {
    root = nullptr;
}

/* Destructor */
template <typename T>
Tree<T>::~Tree() {
    destroy();
}

/* Destroy tree (public method). */
template <typename T>
void Tree<T>::destroy() {
    destroy(root);
}

/* Destroy tree (private method). */
template <typename T>
void Tree<T>::destroy(Node<T> *leaf) {
    if (leaf != nullptr) {
        destroy(leaf->left);
        destroy(leaf->right);
    }
    delete leaf;
}

/* Insert element in the tree (Public methode) */
template <typename T>
void Tree<T>::insert(T key) {
    if (nullptr != root) {
        insert(root, key);
    } else {
        root = new Node<T>;
        root->data = key;
        root->left = nullptr;
        root->right = nullptr;
    }
}

/* 
 * Insert element in the tree (Private methode). This private methode uses in
 * insert() public method.
 */
template <typename T>
void Tree<T>::insert(Node<T> *leaf, T key) {
  if (key < leaf->data){
    if (nullptr != leaf->left) {
        insert(leaf->left, key);
    } else {
        leaf->left = new Node<T>;
        leaf->left->data = key;
        leaf->left->left = nullptr;
        leaf->left->right = nullptr;
    }} else {
        if (nullptr != leaf->right) {
            insert(leaf->right, key);
        } else {
            leaf->right = new Node<T>;
            leaf->right->data = key;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
        }
    }
}

/* Get tree element by value (public methode). */
template <typename T>
Node<T> *Tree<T>::get_element(T key) {
  return get_element(root, key);
}

/* Get tree element by value (Private methode). */
template <typename T>
Node<T> *Tree<T>::get_element(Node<T> *leaf, T key) {
    if (nullptr == leaf) {
        return nullptr;
    } else if (key == leaf->data) {
        return leaf;
    } else if (key < leaf->data) {
        return get_element(leaf->left, key);
    } else return get_element(leaf->right, key);
}

/* 
 * Chekes whether the item is a sheet.
 * If element exist and dont have left and right childs, then it leat.
 */
template <typename T>
bool Tree<T>::isLeafNode(Node<T> *tree) {
    if (nullptr != tree && nullptr == tree->left && nullptr == tree->right) {
        return true;
    } else {
        return false;
    }
}

/* Find max node. */
template <typename T>
Node<T>* Tree<T>::min(Node<T> *tree) {
    if (nullptr == tree) {
        return tree;
    } else if (nullptr == tree->left) {
        return tree;
    } else {
        return min(tree->left);
    }
}

/* Delete tree element by value (public methode). */
template <typename T>
Node<T> *Tree<T>::remove(T key) {
    return remove(root, key);
}

/* Delete tree element by value (Private methode). */
template <typename T>
Node<T> *Tree<T>::remove(Node<T> *tree, T key) {
    Node<T> *temp;
    if (nullptr == tree) {
        return nullptr;
    }

    if (key < tree->data) {
        /* Go in left subtree. */
        tree->left = remove(tree->left, key);
    } else if (key > tree->data) {
        /* Go in right subtree. */
        tree->right = remove(tree->right, key);
    } else {
    /* Chekes whether the item is a sheet. */
    if (isLeafNode(tree)) {
        delete tree;
        tree = nullptr;
    } else if (tree->right && tree->left) {
            Node<T>* temp = min(tree->right);
            tree->data = temp->data;
            tree->right = remove(tree->right, tree->data); 
        } else {
            temp = tree;
            if (nullptr == tree->right) {
                tree = tree->left;
            } else if (nullptr == tree->left) {
                tree = tree->right;
            }
            delete temp;
        }
    }
    return tree;
}

/* 
 * Inorder traversal gives nodes in non-decreasing order.
 * The root of the tree is taken and all the elements are printed in order.
 * The function work recurciv, until the ent of the tree.
 */
template <typename T>
void Tree<T>::in_order_print(Node<T> *tree) {
    if (nullptr != tree) {
        in_order_print(tree->left);
        std::cout << tree->data << " ";
        in_order_print(tree->right);
    }
}

/* Pre_Order traversal. */
template <typename T>
void Tree<T>::pre_order_print(Node<T> *tree) {
    if (nullptr != tree) {
        std::cout << tree->data << " ";
        pre_order_print(tree->left);
        pre_order_print(tree->right);
    }
}

/* Post_Order traversal. */
template <typename T>
void Tree<T>::post_order_print(Node<T> *tree) {
    if (nullptr != tree) {
        post_order_print(tree->left);
        post_order_print(tree->right);
        std::cout << tree->data << " ";
    }
}

/* Level order traversal of a tree is breadth first traversal for the tree. */
template <typename T>
void Tree<T>::level_order_print(Node<T> *tree) {
    /* Tree element are stored in the queue. */
    if (nullptr != tree) {
        std::queue<Node<T>*> queue;
        queue.push(tree);

        /* Tree traversal ends, when the queue is empty. */
        while(!queue.empty()) {
            Node<T> *current = queue.front();
            std::cout << current->data << " ";
            if (current->left) {
                queue.push(current->left);
            }

            if (current->right) {
                queue.push(current->right);
            }
            /* Delete the element. */
            queue.pop();
        }
    }
}

/* Print the elements of a tree with 2 ways. */
template <typename T>
void Tree<T>::display() {
    std::cout << "\nIn_Order_Print: ";
    in_order_print(root);
    std::cout << "\nLevel_Order_Print: ";
    level_order_print(root);
    std::cout << "\nPre_Order_Print: ";
    pre_order_print(root);
    std::cout << "\nPost_Order_Print: ";
    post_order_print(root);
    std::cout << "\n";
}