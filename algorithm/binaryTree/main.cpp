#include "binaryTree.h"


int main() {
    BinaryTree *tree = new BinaryTree;
    int n = 0;
    tree->insert(10);
    tree->insert(20);
    tree->insert(25);
    tree->insert(8);
    tree->insert(9);
    tree->insert(2);
    tree->insert(4);
    tree->insert(1);
    tree->insert(3);
    tree->printTree();
    //Node *max = tree->findMax();
    //std::cout << tree->getLeftHeight() << std::endl;
    //std::cout << tree->getRightHeight() << std::endl;
    //tree->remove(max->value);
    std::cout << "The function gets the number n and returns n-th max value in the tree\n";
    while (true) {
        std::cout << "Enter number ->";
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\nThat input is invalid.  Please try again.!!!!" << std::endl;
        } else {
            std::cin.ignore(32767, '\n');
            break;
        }
    }
    tree->getMaxTime(n);
    tree->printTree();
    return 0;
}