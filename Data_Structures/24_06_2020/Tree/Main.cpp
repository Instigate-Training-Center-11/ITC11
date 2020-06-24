#include <iostream>
#include "Tree.cpp"

int main() {
    Tree<int> *tree = new Tree<int>();

    /* Insert elements in Binary tree. */
    tree->insert(10);
    tree->insert(20);
    tree->insert(30);
    tree->insert(40);
    tree->insert(50);
    tree->insert(60);
    tree->insert(70);
    tree->insert(80);
    
    /* Delete data from tree. */
    if (tree->remove(50)->data) {
        std::cout << "The element is deleted." << "\n";
    } else {
        std::cout << "Not deleted." << "\n";
    }

    /* Print all elements. */
    tree->display();
    std::cout << "\n";

    /* Get data by value. */
    std::cout << "The element with value ";
    std::cout << tree->getElement(60)->data << " is exist." << "\n";
    std::cout << "Its right child is: " << tree->getElement(60)->right->data << "\n";

    /* After using delete tree from heap. */
    delete tree;

    return 0;
}