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
    while(!isEmpty()) {
        pop_front();
    }
}

/*Insert new node*/
template <typename T>
void List<T>::push_back(T value) {
    if (head == NULL) {
        head = new Node<T>(value);
    } else {
        Node<T>* current = this->head;
        while (current->pNext != NULL) {
            current = current->pNext;
        }
        current->pNext = new Node<T>(value);
    }
    size++;
}

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

/*Delete the node of list*/
template <typename T>
void List<T>::pop_front() {
    Node<T>* temp = head;
    head = head->pNext;
    delete temp;
    size--;
}

/*Get the size of list*/
template <typename T>
int List<T>::getSize() {
    return size;
}

/*Display the nodes of list*/
template <typename T>
void List<T>::printf() {
    if (head == NULL) {
        return;
    }
    Node<T> *current = head;
    while (current) {
        std::cout << current->value << " ";
        current = current->pNext;
    }
    std::cout << std::endl;
}

