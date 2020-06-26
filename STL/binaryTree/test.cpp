#include <iostream>
#include <queue>

using namespace std;

struct Node {
  int key;
  Node *left, *right;
  Node (int x) {
     key = x;
     left = right = NULL;
  }
};

void inorder(Node* temp) {
    if (temp != NULL) {
        std::cout << temp->key << " ";
        inorder(temp->right);
        inorder(temp->left);
    }
}

void printLevelOrder(Node *root) {
    if (NULL != root) {
        std::queue<Node*> queue;
        queue.push(root);

        while (!queue.empty()) {
            int nodeCount = queue.size();
            while (nodeCount > 0) {
                Node* node = queue.front();
                std::cout << node->key << " ";
                queue.pop();
                if (NULL != node->left) {
                    queue.push(node->left);
                }

                if (node->right != NULL) {
                    queue.push(node->right);
                }

                --nodeCount;
            }
            std::cout << std::endl;
        }
    }
}

void insert(Node* temp, int key) {
    queue<Node*> q;
    q.push(temp);

    // Do level order traversal until we find
    // an empty place.
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = new Node(key);
            break;
        } else
            q.push(temp->left);

        if (!temp->right) {
            temp->right = new Node(key);
            break;
        } else
            q.push(temp->right);
    }
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(11);
    root->left->left = new Node(7);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    cout << "Inorder traversal before insertion:";
    inorder(root);

    int key = 12;
    insert(root, key);

    cout << endl;
    cout << "Inorder traversal after insertion:";
    inorder(root);
    cout << endl;
    printLevelOrder(root);
    return 0;
}