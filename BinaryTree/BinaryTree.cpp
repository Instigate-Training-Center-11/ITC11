#include <iostream>
#include <queue>
using namespace std;

/* Create the node with key, left, right */
struct Node {
  int key;
  Node * left;
  Node * right;
};

/* Create function for creating nodes */
Node * createNode(int key) {
  Node * node = new Node();
  node - > key = key;
  node - > left = NULL;
  node - > right = NULL;
  return node;
}
/* shaerching algorithm by Level Order Traversal */
Node * search(Node * root, int key) {
  if (root == NULL) {
    return NULL;
  }
  queue < Node * > q;
  Node * out = NULL;;
  q.push(root);

  while (!q.empty()) {
    Node * temp = q.front();
    q.pop();

    if (temp - > key == key) {
      out = temp;
      cout << "Finding element" << endl;
    }
    if (temp - > left != NULL) {
      q.push(temp - > left);
    }
    if (temp - > right != NULL) {
      q.push(temp - > right);
    }
  }
  return out;
}
/* Insert into the first free node by level priority */
void insert(Node ** root, int key) {
  if ( * root == NULL) {
    cout << "The root is NULL" << endl;
    * root = createNode(key);
    return;
  }
  Node * nodeToInsert = createNode(key);
  queue < Node * > q;
  q.push( * root);
  while (!q.empty()) {
    Node * temp = q.front();
    q.pop();
    /* check left */
    if (temp - > left = NULL) {
      temp - > left = nodeToInsert;
      return;
    } else {
      q.push(temp - > left);
    }

    if (temp - > right = NULL) {
      temp - > right = nodeToInsert;
      return;
    } else {
      q.push(temp - > right);
    }
  }
}
void setExtreamRightToNull(Node * root, Node * extreamRight) {
  queue < Node * > q;
  q.push(root);
  Node * temp;
  while (!q.empty()) {
    temp = q.front();
    q.pop();
    if (temp - > left != NULL) {
      if (temp - > left == extreamRight) {
        temp - > left = NULL;
        return;
      }
    }
    if (temp - > right != NULL) {
      if (temp - > right == extreamRight) {
        temp - > right = NULL;
        return;
      }
    }
  }
}
void deleteNode(Node * root, int key) {
  Node * nodeToDelete = search(root, key);
  //   if(nodeToDelete != NULL)
  queue < Node * > q;
  q.push(root);
  Node * temp;
  /* case if on or one of child is empty */
  while (!q.empty()) {
    temp = q.front();
    q.pop();

    if (temp - > left != NULL) {
      q.push(temp - > left);
    }
    if (temp - > right != NULL) {
      q.push(temp - > left);
    }
  }
  /* case if any child is empty */
  int keyAtDeepestRight = temp - > key;

  setExtreamRightToNull(root, temp);

  /* Delete the nodeToDelete; */
  nodeToDelete - > key = keyAtDeepestRight;
}

int main() {
  /* Node *root = createNode(1);
  root->left = createNode(2);    
  root->left->left = createNode(3);
  root->right = createNode(4);
  root->right->right = createNode(4);
  
  Node *node = search(root, 2);
  cout << node->left->key <<endl;
  */

  Node * root = NULL;

  for (int i = 0; i < 5; i++) {
    insert( & root, i);
  }

  cout << root - > key << endl;
  cout << root - > left << endl;
  cout << root - > left - > left << endl;
  cout << root - > right << endl;
  cout << root - > right - > right << endl;
  cout << root - > key << endl;

  deleteNode(root, 2);

  return 0;
}