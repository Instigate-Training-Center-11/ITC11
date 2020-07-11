#include "queue"
#include "Btree.h"
#include <iostream>

template <typename T>
Btree<T>::Btree() {
	root = nullptr;
}

template <typename T>
Node<T>* Btree<T>::createLeaf(T value) {
	Node<T>* n = new Node<T>;
	n->value = value;
	n->left = nullptr;
	n->right = nullptr;
	n->parent = nullptr;

	return n;
}

template <typename T>
void Btree<T>::addLeafPrivate(T value, Node<T>* ptr) {
	Node<T>* leaf = createLeaf(value);

	if (root == nullptr) {
		root = leaf;

	} else if (value < ptr->value) {

		if (ptr->left != nullptr) {
			addLeafPrivate (value, ptr->left);

		} else {

			if (ptr->parent != nullptr &&  ptr->value < (ptr->parent)->value) {
				Node<T>* parent = (ptr->parent)->parent;
				ptr->right = ptr->parent;
				(ptr->right)->parent = ptr;
				ptr->parent = parent;
				if(parent != nullptr) {
					if (parent->value > ptr->value) {
						parent->left = ptr;
					}else {
						parent->right = ptr;
					}
				} else {
					root = ptr;
				}
			}

			ptr->left = leaf;
			leaf->parent = ptr;

		}
	} else if (value > ptr->value) {

		if (ptr->right != nullptr) {
			addLeafPrivate (value, ptr->right);

		} else {

			if (ptr->parent != nullptr &&  ptr->value > (ptr->parent)->value) {
				Node<T>* parent = (ptr->parent)->parent;
				ptr->left = ptr->parent;
				(ptr->left)->parent = ptr;
				ptr->parent = parent;
				if(parent != nullptr) {
					if (parent->value > ptr->value) {
						parent->left = ptr;
					}else {
						parent->right = ptr;
					}
				} else {
					root = ptr;
				}
			}

			ptr->right = leaf;
			leaf->parent = ptr;
		}

	} else {
		std::cout << "This value already added." << std::endl;

	}
}

template <typename T>
void Btree<T>::addLeaf(T value) {
	addLeafPrivate(value, root);
}

template <typename T>
void Btree<T>::printPrivate(Node<T>* ptr) {
	if (root != nullptr) {

		if (ptr->left != nullptr) {
			printPrivate(ptr->left);

		}
		std::cout << ptr->value << "\t";

		if (ptr->right != nullptr) {
			printPrivate(ptr->right);

		}
	} else {
		std::cout << "The tree is empty." << std::endl;

	}
}

template <typename T>
void Btree<T>::print() {
	printPrivate(root);
}

template <typename T>
void Btree<T>::levelOrderPrint() {
	/* If root is not NULL */
	if (NULL != root) {
		/* Create queue for level elements */
		std::queue<Node<T>*> queue;
		queue.push(root);

		/* Pop current level elements from queue and push current's left and right */
		while (!queue.empty()) {
			Node<T>* node = queue.front();
			std::cout << node->value << " ";
			queue.pop();

			if (node->left) {
				queue.push(node->left);
			}

			if (node->right) {
				queue.push(node->right);
			}
		}

		std::cout << std::endl;
	}
}

template <typename T>
Node<T>* Btree<T>::getNodePrivate(T value,  Node<T>* ptr){
	if (ptr != nullptr) {

		if (ptr->value == value) {
			return ptr;

		} else {

			if (value < ptr->value) {
				return getNodePrivate(value, ptr->left);

			} else {
				return getNodePrivate(value, ptr->right);

			}

		}
	} else {
		return nullptr;
	}


}

template <typename T>
Node<T>* Btree<T>::getNode(T value){
	return getNodePrivate(value, root);
}

template <typename T>
T Btree<T>::findMinPrivate(Node<T>* ptr) {
	if (root == nullptr) {
		std::cout << "The tree is empty" << std::endl;
		return T();

	} else {

		if (ptr->left != nullptr) {
			return findMinPrivate(ptr->left);

		} else {
			return ptr->value;

		}
	}

}

template <typename T>
T Btree<T>::findMin() {
	return findMinPrivate(root);
}

template <typename T>
void Btree<T>::removeRoot() {
	if (root != nullptr){
		Node<T>* delPtr = root;
		T minInRighTree;

		if (root->left == nullptr && root->right == nullptr) {
			root = nullptr;
			delete delPtr;

		} else if (root->left == nullptr && root->right != nullptr) {
			root = root->right;
			delPtr->right = nullptr;
			delete delPtr;

		} else if (root->left != nullptr && root->right == nullptr) {
			root = root->left;
			delPtr->left = nullptr;
			delete delPtr;

		} else {
			minInRighTree = findMinPrivate(root->right);
			removeNodePrivate(minInRighTree, root);
			root->value = minInRighTree;

		}
	} else {
		std::cout << "The tree is empty." << std::endl;
	}
}

template <typename T>
void Btree<T>::removeMatch(Node<T>* parent, Node<T>* match, bool left) {
	if (root != nullptr) {
		Node<T>* delPtr;
		T minInRighTree;

		if (match->left == nullptr && match->right == nullptr) {
			delPtr = match;
			left == true ? parent->left = nullptr : parent->right = nullptr;
			delete delPtr;

		} else if (match->left == nullptr && match->right != nullptr) {
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right =nullptr;
			delPtr = match;
			delete delPtr;

		} else if (match->left != nullptr && match->right == nullptr) {
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left =nullptr;
			delPtr = match;
			delete delPtr;

		} else {
			minInRighTree = findMinPrivate(match->right);
			removeNodePrivate(minInRighTree, match);
			match->value = minInRighTree;

		}
	} else {
		std::cout << "The tree is empty." << std::endl;

	}

}

template <typename T>
void Btree<T>::removeNodePrivate(T value, Node<T>* parent) {
	if (root != nullptr) {

		if (root->value == value) {
			removeRoot();

		} else {

			if(value < parent->value){
				parent->left->value == value ? removeMatch(parent, parent->left, true) :
					removeNodePrivate(value, parent->left);

			} else if(value > parent->value){
				parent->right->value == value ? removeMatch(parent, parent->right, false) :
					removeNodePrivate(value, parent->right);

			} else {
				std::cout << "The value wasn't found." << std::endl;

			}

		}
	} else {
		std::cout << "The tree is empty." << std::endl;
	}
}

template <typename T>
void Btree<T>::removeNode(T value) {
	removeNodePrivate(value, root);
}

template <typename T>
void Btree<T>::removeSubTree(Node<T>* ptr) {
	if (ptr != nullptr) {

		if (ptr->left != nullptr) {
			removeSubTree(ptr->left);

		}
		if (ptr->right != nullptr) {
			removeSubTree(ptr->right);

		}
		delete ptr;
	}
}

template <typename T>
Btree<T>::~Btree() {
	removeSubTree(root);
}