#include <iostream>
#include "btree.cpp"


int main() {

	/* btree tree; */
	btree *tree = new btree();

	tree->insert(8);
	tree->insert(7);
	tree->insert(10);
	tree->insert(9);
	tree->insert(3);
	tree->insert(4);
	tree->insert(2);

	tree->preorderPrint();
	tree->inorderPrint();
	tree->postorderPrint();

	delete tree;

}
