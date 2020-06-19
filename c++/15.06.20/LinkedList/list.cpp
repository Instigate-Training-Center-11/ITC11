#include <iostream>
#include "list.hpp"

/*Constructor*/
List::List() {
    size = 0;
    head = NULL;
}

/*Destructor*/
List::~List() {
    clear();
}

/*Insert new node*/
void List::push_back(int value) {
    if (NULL == head) {
        head = new Node(value);
    } else {
        Node* current = this->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new Node(value);
    }
    size++;
}

/*Insert new node from the front of list*/
void List::push_front(int value) {
    head = new Node(value, head);
    size++;
}

/*Access to the element by index*/
int& List::operator[](const int index) {
    int count = 0;
    Node* current = this->head;
    while (current != NULL) {
        if (count == index) {
            return current->value;
            count++;
        }
    }
}

/*Check the list is empty or not*/
bool List::isEmpty() {
    return NULL == head;
}

/*Delete the node at the front of list*/
void List::pop_front() {
    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
}

/*Add a new node by index*/
void List::add(int value, int index) {
    if (index == 0) {
        push_front(value);
    } else {
        Node* current = this->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node *newNode = new Node(value, current->next);
        current->next = newNode;
        size++;
    }
}

/*Delete the list*/
void List::clear() {
    while (size) {
        pop_front();
    }
}

/*Get the size of list*/
int List::getSize() {
    return size;
}

/*Display the nodes of list*/
void List::printf() {
    if (NULL == head) {
        return;
    }
    Node *current = head;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
