#include "binaryTree.h"


int BinaryTree::getMaxTime(int n) {
    if (n > this->getCountNodes()) {
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        this->remove(this->findMax()->value);
        this->buildTree(this->getRoot());
    }

    return this->findMax()->value;
}

void BinaryTree::storeBSTNodes(Node *root, std::vector<Node*> &nodes) {
    if (root == NULL) {
        return;
    }

    storeBSTNodes(root->left, nodes);
    nodes.push_back(root);
    storeBSTNodes(root->right, nodes);
}

Node* BinaryTree::buildTreeUtil(std::vector<Node*> &nodes, int start,int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *root = nodes[mid];

    /* Using index in Inorder traversal, construct
     * left and right subtress */
    root->left = buildTreeUtil(nodes, start, mid - 1);
    root->right = buildTreeUtil(nodes, mid + 1, end);

    return root;
}

void BinaryTree::buildTree(Node *root) {
    /* Store nodes of given BinaryTree in sorted order */
    std::vector<Node *> nodes;
    storeBSTNodes(root, nodes);

    /* Constucts BinaryTree from nodes[] */
    int n = nodes.size();
    this->root = buildTreeUtil(nodes, 0, n - 1);
}

void BinaryTree::insert(Node *root, int value) {
    if (value > root->value) {
        if (!root->right) {
            root->right = new Node(value);
            ++countNodes;
        } else {
            insert(root->right, value);
        }
    } else {
        if (!root->left) {
            ++countNodes;
            root->left = new Node(value);
        } else {
            insert(root->left, value);
        }
    }
}

void BinaryTree::insert(int value) {
    if (!root){
        root = new Node(value);
    } else {
        this->insert(root, value);
    }

}

void BinaryTree::print(Node *root) {
    if (!root) {
        return;
    }

    std::cout << root->value << ' ';
    print(root->left);
    print(root->right);
}

void BinaryTree::printTree() {
    if(!root) {
        return;
    }

    print(root);
    std::cout << "\n";
}

Node* BinaryTree::findMax() {
    Node *max = root;

    while (max->right) {
        max = max->right;
    }

    return max;
}

bool BinaryTree::remove(Node *parent, Node *current, int value) {
    if (!current) {
        return false;
    }

    if (current->value == value) {

        if (!current->left && !current->right) {
            if (parent->right == current) {
                parent->right = NULL;
            } else {
                parent->left = NULL;
            }
            delete current;
            --this->countNodes;
            current = NULL;
            return true;
        } else if (!current->left || !current->right) {
            Node *child = current->left;
            if (!child) {
                child = current->right;
            } if (!parent) {
                this->root = child;
            } else {
                if (child->value > parent->value) {
                    parent->right = child;
                } else {
                    parent->left = child;
                }
            }
            delete current;
            current = NULL;
        } else {
            Node *nextLargerNode = nextLarger(current);
            current->value = nextLargerNode->value;
            delete nextLargerNode;
            nextLargerNode = NULL;
            --this->countNodes;
        }
        return true;
    }

    if (value > current->value) {
        return remove(current, current->right, value);
    } else {
        return remove(current, current->left, value);
    }
}


bool BinaryTree::remove(int value) {
    return remove(NULL, root, value);
}

Node* BinaryTree::nextLarger(Node *node) {
    Node *nextLarger = node->right;
    while (nextLarger->left) {
        nextLarger = nextLarger->left;
    }

    return nextLarger;
}

Node* BinaryTree::findNodeWithValue(int value) {
    Node *current = root;
    while (current) {
        if (current->value == value) {
            break;
        }
        if (value > current->value) {
            current = current->right;
        } else {
            current = current->left;
        }
    }

    return current;
}

BinaryTree::BinaryTree(void) {
}
BinaryTree::~BinaryTree(void) {
    delete root;
}

Node* BinaryTree::getRoot() {
    return this->root;
}

int BinaryTree::getCountNodes(void) {
    return this->countNodes;
}