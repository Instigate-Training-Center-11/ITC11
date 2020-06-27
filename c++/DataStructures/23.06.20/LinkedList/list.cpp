#include <iostream>
#include "list.h"
#include "iterator.h"

/*Constructor*/
template<typename T>
List<T>::List() {
    length = 0;
    head = NULL;
    tail = NULL;
}

/*Destructor*/
template<typename T>
List<T>::~List() {
    Node<T> *tmp = NULL;
    Node <T> *current = head;
    while (current != NULL) {
        tmp = current;
        current =current->next;
        delete tmp;
    }
}

template<typename T>
typename List<T>::iterator List<T>::begin() {
            return iterator(head->next);
}

template<typename T>
typename List<T>::iterator List<T>::end() {
            return iterator(tail);
}

/*Insert new node*/
template<typename T>
void List<T>::push_back(const T& value) {
    Node<T>* current = new Node<T>(value);
    if (NULL == tail) {
        head = tail = current;
    } else {
        tail->next = current;
        current->prev = tail;
        tail = current;
    }
    ++length;
}

/*Insert new node from the front of list*/
template<typename T>
void List<T>::push_front(const T& value) {
    Node<T>* current = new Node<T>(value);
    if (NULL == head) {
        head = tail = current;
    } else {
        current->next = head;
        head->prev = current;
        head = current;
    }
    ++length;
}

/*Check the list is empty or not*/
template<typename T>
bool List<T>::isEmpty() {
    return NULL == head;
}

/*Delete the node at the front of list*/
template<typename T>
void List<T>::pop_front() {
    if (!isEmpty()) {
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
    }
    --length;
}

/*Delete the node at the back of list*/
template<typename T>
void List<T>::pop_back() {
    if (!isEmpty()) {
        Node<T>* tmp = tail;
        tail = tail->prev;
        delete tmp;
    }
    length--;
}
/* function will return Size of the vector */
template <typename T>
unsigned int List<T>::size() const {
    return length;
}

/*Display the nodes of list*/
template <typename T>
void List<T>::print() {
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

