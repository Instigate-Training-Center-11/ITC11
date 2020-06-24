#include <iostream>
#include "List.h"

template<typename T>
List<T>::List() {
    first = new Node<T>();
    last = new Node<T>();
    first->prev = nullptr;
    first->next = last;
    last->prev = first;
    last->next = nullptr;
    length = 0;
}

template<typename T>
List<T>::List(const List<T>& list) {
    first = new Node<T>();
    last = new Node<T>();
    first->prev = nullptr;
    first->next = last;
    last->prev = first;
    last->next = nullptr;
    length = 0;
    for (Node<T> *pointer = list.first; pointer != 0; pointer = pointer->next) {
        push_back(pointer->data);
    }    
}

template <typename T>
List<T>::List(Node<T> *list) : List<T>() {
    *this = list;
}

template<typename T>
List<T>::~List() {
	while (first->next != nullptr) {
        Node<T> *tmp = first;
        first = first->next;
        delete tmp;
    }
    delete first;
}

template<typename T>
typename List<T>::iterator List<T>::begin() {
    return iterator(first->next);
}

template<typename T>
typename List<T>::iterator List<T>::end() {
    return iterator(last);
}

template<typename T>
void List<T>::push_back(const T& value) {
    Node<T> *newNode = new Node<T>;
    newNode->prev = 0;
    newNode->next = 0;
    newNode->data = value;
    if (0 == first) {
        last = new Node<T>;
        first = newNode;
        first->next = last;
        last->prev = first;
    } else {
        last->prev->next = newNode;
        newNode->prev = last->prev;
        newNode->next = last;
        last->prev = newNode;
    }
    length = length + 1;
}

template<typename T>
void List<T>::push_front(const T& value) {
    if (0 == length) {
        push_back(value);
        return;
    } else {
        Node<T> *pointer = new Node<T>(value, 0, first->next);
        first->next = pointer;
    }
    length = length + 1;
}

template<typename T>
void List<T>::pop_front() {
    if (0 == length) {
        std::cout << "The list is empty";
    }
    Node<T> *tmp = first;
    first = first->next;		
    delete tmp;
    length = length - 1;
}

template<typename T>
void List<T>::pop_back() {
    if (0 == length) {
        std::cout << "The list is empty";
    }
    if (last == first) {
        return;
    }
    last = last->prev;
    length = length - 1;
}

template<typename T>
T& List<T>::front() {
    if (0 == length) {
        std::cout << "The list is empty";
    }
    return first->next->data;
}

template<typename T>
T& List<T>::back() {
    if (0 == length) {
        std::cout << "The list is empty";
    }
    return last->prev->data;
}

template<typename T>
unsigned int List<T>::size() const {
    return length;
}

template<typename T>
bool List<T>::empty() const {
    if (0 >= length) {
        return true;
    }
    return false;
}

template <typename T>
void List<T>::insert(int pos, T theData) {
    int index = 0;
    Node<T> *current = first;
    while (0 != current) {
        if (index++ == pos + 1) {
            Node<T> *newNode = new Node<T>;
            newNode->data = theData;
            newNode->prev = current->prev;
            newNode->next = current;
            if (0 != newNode->prev) {
                newNode->prev->next = newNode;
            }
            current->prev = newNode;
        }
        current = current->next;
    }
}