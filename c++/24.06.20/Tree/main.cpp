#include <iostream>
#include "tree.h"
#include "tree.cpp"

int main(){
    Tree<int> *tree = new Tree<int>();
    tree->insert(10);
    tree->insert(6);
    tree->insert(14);
    tree->insert(5);
    tree->insert(8);
    tree->insert(11);
    tree->insert(18);
    std::cout << "==Level Order==" << std::endl;
    tree->levelOrderPrint();
    std::cout << "==In Order==" << std::endl;
    tree->inorderPrint();

    delete tree;
}
