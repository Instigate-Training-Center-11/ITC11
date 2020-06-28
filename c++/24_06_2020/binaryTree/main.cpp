#include "tree.h"

enum print {inOrder, postOrder,  preOrder};

int main() {

    BinaryTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.display(inOrder);
    tree.display(postOrder);
    tree.display(preOrder);
    return 0;
}