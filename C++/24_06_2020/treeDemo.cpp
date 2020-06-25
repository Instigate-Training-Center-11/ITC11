#include <iostream>
using namespace std;

class Node {
	int value;
	Node *left;
	Node *right;
public:	
	Node() {
		value = -1;
		left = NULL;
		right = NULL;
	}

	Node* getLeft() {
		return left;
	}

	void setLeft(Node *lef = NULL) {
		left = lef;
	}

	void setRight(Node *rig = NULL) {
		right = rig;
	}

	Node* getRight() {
		return right;
	}

	int getValue() {
		return value;
	}

	void setValue(int val) {
		value = val;
	}
};

class TreeDemo{
	Node *root;
public:
	TreeDemo();
	~TreeDemo();

	void insert(int value, Node *element = NULL);
	void toString(Node *element = NULL);
	Node *search(int value, Node *elemenat = NULL);
	void clear(Node *element = NULL);
};


TreeDemo::TreeDemo() {
	root = NULL;
}

TreeDemo::~TreeDemo() {
	clear(root);
}

void TreeDemo::insert(int value, Node *element) {
	static int i = 0;
	if(i == 0) {
		root = new Node();
		root -> setValue(value);
		++i;
		return;
	} 

	if(element == NULL) {
		element = root;
	}

	if(value < element -> getValue()) {
		//cout << value  << endl;
		Node *lef = element -> getLeft();
		if(lef != NULL) {
			insert(value, lef);
		} else {
			lef = new Node();
			lef -> setValue(value);
			element -> setLeft(lef);
			//cout << lef -> getValue()  << endl;
		}
	} else if(value >= element -> getValue()) {
		//cout << value  << endl;
		Node *rig = element -> getRight();
		if(rig != NULL) {
			insert(value, rig);
		} else {
			rig = new Node();
			rig -> setValue(value);
			element -> setRight(rig);
			//cout << rig -> getValue()  << endl;
		}
	}

}

Node *TreeDemo::search(int value, Node *element) {
	if(element == NULL) {
		element = root;
	}
	if(element != NULL) {
		if(value == element -> getValue()) {
			return element;
		}
		if(value < element -> getValue()) {
			search(value, element -> getLeft());
		} else {
			search(value, element -> getRight());
		}
	} else {
		return NULL;
	}
}

void TreeDemo::clear(Node *rt) {
	static int j = 0;
	if(j == 0) {
		rt = root;
		++j;
		root = NULL;
	}
	if(rt != NULL) {
		clear(rt -> getLeft());
		clear(rt -> getRight());
		delete rt;
	}
}

void TreeDemo::toString(Node *element) {
	//cout << root -> getValue() << endl;
	if(element == NULL) {
		element = root;
		if(root == NULL) {
			cout << "Is empty!" << endl;
			return;
		}
	}

	if(element != NULL) {
		//cout << element -> getLeft() << endl;
		if(element -> getLeft() != NULL) {
			toString(element -> getLeft());
		}
			cout << element -> getValue() << "\t";
		if(element -> getRight() != NULL) {
			toString(element -> getRight());
		}
	}
}

int main() {
	TreeDemo tree;
	tree.insert(7);
	tree.insert(3);
	tree.insert(6);
	
	cout << "show by order!"  << endl;
	tree.toString();
	cout << endl;
	
	Node *node = tree.search(3);
	cout << "sarch(3) -> getValue() :" << node -> getValue() << endl;

	tree.clear();
	cout << "clear() & show()"  << endl;
	tree.toString();
	cout << endl;
	return 0;
}

