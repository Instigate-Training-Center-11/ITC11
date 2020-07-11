#include "binaryTree.h"

int validationInteger(void);
unsigned int validationUnsigned(void);

int main() {
    BinaryTree *tree = new BinaryTree;
    unsigned int nodeCount = validationUnsigned();
    unsigned int n = 0;
    for (int i = 0; i < nodeCount; ++i) {
        std::cout << "Enter value Node["<< i <<"] = ";
        tree->insert(validationInteger());
    }

    tree->buildTree(tree->getRoot());
    tree->printTree();
    n = validationUnsigned();
    std::cout << "The function gets the number n and returns n-th max value in the tree\n";
    std::cout << n << "-th max value is -> " << tree->getMaxTime(n) << std::endl;
    delete tree;
    return 0;
}

int validationInteger(void) {
    int n = 0;
    while (true) {
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
    return n;
}

unsigned int validationUnsigned(void) {
    int nodeCount = 0;
    while (true) {
        std::cout << "Enter count Nodes-> ";
        std::cin >> nodeCount;
        if (std::cin.fail() | nodeCount < 0) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\nThat input is invalid.  Please try again.!!!!" << std::endl;
        } else {
            std::cin.ignore(32767, '\n');
            break;
        }
    }
    return nodeCount;
}
