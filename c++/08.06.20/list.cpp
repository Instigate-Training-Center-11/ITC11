#include <iostream>
#include "list.hpp"

/*Constructor*/
template <typename T>
List<T>::List() {
    size = 0;
    head = NULL;
}

/*Destructor*/
template <typename T>
List<T>::~List() {
    clear();
}

/*Insert new node*/
template <typename T>
void List<T>::push_back(T value) {
    if (NULL == head) {
        head = new Node<T>(value);
    } else {
        Node<T>* current = this->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new Node<T>(value);
    }
    size++;
}

/*Insert new node from the front of list*/
template <typename T>
void List<T>::push_front(T value) {
    head = new Node<T>(value, head);
    size++;
}

/*Access to the element by index*/
template <typename T>
T& List<T>::operator[](const int index) {
    int count = 0;
    Node<T>* current = this->head;
    while (current != NULL) {
        if (count == index) {
            return current->value;
        }
        current = current->pNext;
        count++;
    }
}

/*Check the list is empty or not*/
template <typename T>
bool List<T>::isEmpty() {
    return NULL == head;
}

/*Delete the node at the front of list*/
template <typename T>
void List<T>::pop_front() {
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    size--;
}

/*Add a new node by index*/
template <typename T>
void List<T>::add(T value, int index) {
    if (index == 0) {
        push_front(value);
    } else {
        Node<T>* current = this->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node<T> *newNode = new Node<T>(value, current->next);
        current->next = newNode;
        size++;
    }
}

/*Delete the list*/
template <typename T>
void List<T>::clear() {
    while (size) {
        pop_front();
    }
}

/*Get the size of list*/
template <typename T>
int List<T>::getSize() {
    return size;
}

/*Display the nodes of list*/
template <typename T>
void List<T>::printf() {
    if (NULL == head) {
        return;
    }
    Node<T> *current = head;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

