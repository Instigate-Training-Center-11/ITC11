#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void nodeInit(struct Node *head, int n){
    head->data = n;
    head->next =NULL;
}

void addNode(struct Node *head, int n) {
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;

    Node *current = head;
    while(current) {
        if(current->next == NULL) {
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}

void insertFront(struct Node **head, int n) {
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = *head;
    *head = newNode;
}

struct Node *searchNode(struct Node *head, int n) {
    Node *current = head;
    while(current) {
        if(current->data == n) return current;
        current = current->next;
    }
    cout << "Not finded " << n << " in list." << '\n';
}

bool deleteNode(struct Node **head, Node *ptrDel) {
    Node *current = *head;
    if(ptrDel == *head) {
        *head = current->next;
        delete ptrDel;
        return true;
    }
    
    while(current) {
        if(current->next == ptrDel) {
            current->next = ptrDel->next;
            delete ptrDel;
            return true;
        }
        current = current->next;
    }
    return false;
}

/* reverse the list */
struct Node* reverse(struct Node** head) {
    Node *parent = *head;
    Node *me = parent->next;
    Node *child = me->next;

    /* make parent as tail */
    parent->next = NULL;
    while(child) {
        me->next = parent;
        parent = me;
        me = child;
        child = child->next;
    }
    me->next = parent;
    *head = me;
    return *head;
}

/* make a copy of a linked list */
void copyLinkedList(struct Node *node, struct Node **pNew) {
    if(node != NULL) {
        *pNew = new Node;
        (*pNew)->data = node->data;
        (*pNew)->next = NULL;
        copyLinkedList(node->next, &((*pNew)->next));
    }
}

void deleteLinkedList(struct Node **node) {
    struct Node *tmpNode;
    while(*node) {
        tmpNode = *node;
        *node = tmpNode->next;
        delete tmpNode;
    }
}

void display(struct Node *head) {
    Node *list = head;
    while(list) {
        cout << list->data << " ";
        list = list->next;
    }
    cout << endl;
    cout << endl;
}

