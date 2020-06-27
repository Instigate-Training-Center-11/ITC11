#include <iostream>

#include "tree.h"

#include "node.h"
#include "node.cpp"

/* member function for insert function to insert a new nod in a tree */
template <typename T>
void Tree<T>::insert(Node<T>* root, T value)
{
    if (value < root->value)
    {
        /* if value to insert is lower then root */
        if (!root->left)
            root->left = new Node<T>(value);
        else
            insert(root->left, value);
    }
    else
    {
        /* if value to insert is greater then root */
        if (!root->right)
            root->right = new Node<T>(value);
        else
            insert(root->right, value);
    }
}

/* member function to insert a new nod in a tree */
template <typename T>
void Tree<T>::insert(T value)
{
    /* first of all check if tree is empty or not*/    
    if (!root){
        root = new Node<T>(value);
    }
    else
    {
        this->insert(root, value);
    }
}

/*member function to search a value in the tree*/
template <typename T>
Node<T>* Tree<T>::getNodeByValue(T value)
{
    Node<T>* temp = root;
    while (temp)
    {   
        if (value == temp->value)
        {
            break;
        }
        else if (value > temp->value)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return temp;
}

/* member function for remove function to remove a node of a tree */
template <typename T>
bool Tree<T>::removeNodeByPtr(Node<T>* head, Node<T>* temp, T value)
{
    /* check whether tree has any node with given value */
    if (!temp)
    {
        std::cout << "Binery Search Tree hasn't any node with such value." << std::endl;
        return false;
    }

    if (temp->value == value)
    {
        /* check if node to delete is leaf */
        if (!temp->right && !temp->left)
        {
            if (head->right == temp)
            {
                head->right = NULL;
            }    
            else
            {
                head->left = NULL;
            }
            delete temp;
            temp = NULL;
            return true;
        }
        /* check if node to delete has a child */
        else if (!temp->right || !temp->left)
        {
            Node<T>* child = temp->left;

            if (!child)
            {
                child = temp->right;
            }

            /* if chiled becomes a root */
            if (!head)
            {
                this->root = child;
            }
            else
            {
                if (child->value > head->value)
                {
                    head->right = child;
                }
                else
                {
                    head->left = child;
                }
            }

            delete temp;
            temp = NULL;
        }
        /* if temp has two children */
        else
        {
            Node<T>* nextMax = temp->right;

            while (nextMax->left)
            {
                nextMax = nextMax->left;
            }

            temp->value = nextMax->value;
            delete nextMax;
            nextMax = NULL;
        }

        return true;
    }

    /* find the right node to remove */
    if (value < temp->value)
    {
        return removeNodeByPtr(temp, temp->left, value);
    }
    else
    {
        return removeNodeByPtr(temp, temp->right, value);
    }
}

/* member function to remove a node of a tree */
template <typename T>
bool Tree<T>::remove(T value)
{
    return removeNodeByPtr(NULL, root, value);
}

/* desplay inorder traversal of a tree */
template <typename T>
void Tree<T>::inorderPrint(Node<T>* root)
{
    if (root == NULL)
    {
        return;
    }

    inorderPrint(root->left);
    std::cout << root->value << ' ';
    inorderPrint(root->right);
}

/* desplay postorder traversal of a tree */
template <typename T>
void Tree<T>::postorderPrint(Node<T>* root)
{
    if (root == NULL)
    {
        return;
    }

    postorderPrint(root->left);
    postorderPrint(root->right);
    std::cout << root->value << ' ';
}

/* desplay preorder traversal of a tree */
template <typename T>
void Tree<T>::preorderPrint(Node<T>* root)
{
    if (root == NULL)
    {
        return;
    }

    std::cout << root->value << ' ';
    preorderPrint(root->left);
    preorderPrint(root->right);
}

/* desplay levelorder traversal of a tree */
template <typename T>
void Tree<T>::levelorderPrint(Node<T>* root)
{
    if (root == NULL)
    {
        return;
    }

    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        printLevel(root, i);
    }
}

/*print nodes at a given level*/
template <typename T>
void Tree<T>::printLevel(Node<T>* root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (level == 1)
    {
        std::cout << root->value << " ";
    }
    else if (level > 1)
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

/* compute the number of nodes along the longest path from the root node
down to the farthest leaf node */
template <typename T>
int Tree<T>::height(Node<T>* node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }   
}

/* desplay tree in several traversals */
template <typename T>
void Tree<T>::print()
{
    std::cout << "\n======== Binary Search Tree ========" << std::endl;
    std::cout << "Inorder travesal: ";
    inorderPrint(root);
    std::cout << std::endl;

    std::cout << "Postorder travesal: ";
    postorderPrint(root);
    std::cout << std::endl;

    std::cout << "Preorder travesal: ";
    preorderPrint(root);
    std::cout << std::endl;

    std::cout << "Levelorder travesal: ";
    levelorderPrint(root);
    std::cout << std::endl;
}