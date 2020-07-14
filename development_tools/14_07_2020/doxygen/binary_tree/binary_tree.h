#include "node.h"

#ifndef BINARYTREE_H
#define BINARYTREE_H

    /*
    Here is implemented the binary_tree.h file for the
    BinaryTree<T> class created by the user.
    */

    /**
    * @brief Implimentation binary tree
    * @version 1.0.0
    */
    template <typename T>
    class BinaryTree {
        private:
            Node<T> *root;
            Node<T> *makeEmpty(Node<T> *);
            Node<T> *insert(T, Node<T> *);
            Node<T> *findMin(Node<T> *);
            Node<T> *findMax(Node<T> *);
            Node<T> *remove(T, Node<T> *);
            void inOrder(Node<T> *);
            void levelOrder(Node<T>*);
            Node<T> *getElement(Node<T> *, T);
        public:
            BinaryTree();
            ~BinaryTree();

            /**
             * @brief Insert the element in binary tree
             * @param index need get in function
             */
            void insert(T index);

            /**
             * @brief removed the element in binary tree
             * @param index need get in function
             */
            void remove(T index);

            /**
             * @brief Traversal on elements in binary tree
             */
            void inOrder();

            /**
             * @brief Traversal on elements in binary tree
             */
            void levelOrder();

            /**
             * @brief Search the element in binary tree
             * @param element need get in function
             * @return return object Node
             */
            Node<T> *search(T element);
    };

#endif