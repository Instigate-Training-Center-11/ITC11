#include<iostream>
#include"list.hpp"

/*Constructor*/
List::List(void) {
    m_head = NULL;
}

/*Copy Constructor*/
List::List(List& list) {
    std::cout << "Copy constructor called " << std::endl;
    int index;
    Node* next;
    this->m_head = NULL;
    if (!list.isEmpty()) {
        Node *current = list.m_head;
        while (NULL != current) {
            this->add(current->value, index);
            current = current->next;
        }
    }
}

/*Destructor*/
List::~List(void) {
    while (!isEmpty()) {
        remove(0);
    }
}

/*Insert new node*/
void List::add(int val, int index) {
    Node* newNode = new Node(val);
    if (NULL == m_head || 0 == index) {
        newNode->next = m_head;
        m_head = newNode;
        return;
    }
    int size = getSize();
    if (index > size) {
        index = size;
    }
    Node* current = m_head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

/*Check the list is empty or not*/
bool List::isEmpty() {
    return NULL == m_head;
}

/*Delete the node of list*/
void List::remove(int index) {
    Node* current = m_head;
    if (isEmpty() || index > getSize() - 1) {
        return;
    } else if (0 == index) {
        current = m_head;
        m_head = m_head->next;
    } else {
        for (int i = 0; i < index - 2; i++) {
            current = current->next;
        }
        Node* temp = current;
        current = current->next;
        temp->next = current->next;
    }
    delete current;
}

/*Get the size of list*/
int List::getSize() {
    int size = 0;
    Node* current = m_head;
    while (current != NULL) {
        current = current->next;
        size++;
    }
    return size;
}

/*Display the nodes of list*/
void List::printf() {
    if (m_head == NULL) {
        return;
    }
    Node *current = m_head;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

/*Get the element by index*/
int List::getElement(int index) {
    Node* current = m_head;
    int count = 0;
    while (NULL != current) {
        if (count == index) {
            return current->value;
        }
        count++;
        current = current->next;
    }
}

