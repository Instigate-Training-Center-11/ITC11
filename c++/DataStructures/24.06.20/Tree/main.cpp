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
    tree->insert(15);
    std::cout << "==After insert a new element==" << std::endl;
    std::cout << "==In Order==" << std::endl;
    tree->inorderPrint();
    std::cout << "==In Preorder==" << std::endl;
    tree->preorderPrint();
    std::cout << "==In Postorder==" << std::endl;
    tree->postorderPrint();

    delete tree;
}
