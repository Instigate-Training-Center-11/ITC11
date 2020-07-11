#ifndef BTREE__H
#define BTREE__H

template <typename T>
struct Node {
	T value;
	Node* left;
	Node* right;
	Node* parent;
	int height;
	T& operator* () {
		return value;
	}
};

template <typename T>
class Btree {
private:
	Node<T>* root;
	Node<T>* createLeaf(T);
	Node<T>* addLeafPrivate(T, Node<T>*);
	void printPrivate(Node<T>*);
	Node<T>* getNodePrivate(T, Node<T>*);
	T findMinPrivate(Node<T>*);
	void removeRoot();
	void removeMatch(Node<T>*, Node<T>*, bool);
	void removeNodePrivate(T, Node<T>*);
	void removeSubTree(Node<T>*);
	int height(Node<T>*);
	Node<T>* rightBalance(Node<T>*);
	Node<T>* leftBalance(Node<T>*);
	Node<T>* doubleBalanceLeft(Node<T>*);
	Node<T>* doubleBalanceRight(Node<T>*);

public:
	Btree();
	~Btree();

	void addLeaf(T);
	void print();
	void levelOrderPrint();
	Node<T>* getNode(T);
	T findMin();
	void removeNode(T);
};

#endif