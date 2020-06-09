#include <iostream>
#include "list.h"
#include "my_exception.h"

/*
By user created Nde type description.
Difoult constructor of List.
*/
template <typename T>
List<T>::List() {
    size = 0;
    first = nullptr;
}

/* This methog allows you to apply List elements with [] simbols. */
template <typename T>
T& List<T>::operator[](int index) {
    if (index >= size || index < 0) {
        throw MyException("You can't get an element too much!!!");
    }

    int count = 0;
    Node<T> *current = this->first;
    while (current != nullptr) {
    if (count == index) {
            return current->data;
        }

        current = current->ptr;
        ++count;
    }
}

/* This method adds an element to the front of the list. */
template <typename T>
void List<T>::pushFront(T data) {
    first = new Node<T>(data, first);
    ++List::size;
}

/* This method adds an element to the given index of the list. */
template <typename T>
void List<T>::insert(T data, int index) {
    if(index > size || index < 0) {
        throw MyException("Do not add too much element!!!");
    }

    if (index == 0) {
        pushFront(data);
    } else {
        Node<T> *pre = first;
        for (int i = 0; i < index - 1; ++i) {
            pre = pre->ptr;
        }

        Node<T> *insertNode = new Node<T>(data, pre->ptr);
        pre->ptr = insertNode;
        ++List::size;
    }
}

/* This method deletes an element to the given index of the list. */
template <typename T>
void List<T>::remove(int index) {
    if (index >= size || index < 0) {
        throw MyException("Do not remove too much element!!!");
    }

    if (index == 0) {
        popFront();
    } else {
        Node<T> *post = first;
        for (int i = 0; i < index - 1; ++i) {
            post = post->ptr;
        }

        Node<T> *newNode = post->ptr->ptr;
        post->ptr = newNode;
        --List::size;
    }
}

/* This method deletes an element to the front of the list. */
template <typename T>
void List<T>::popFront() {
    Node<T> *temp = first;
    first = first->ptr;
    delete temp;
    --List::size;
}

/* This method deletes all List. */
template <typename T>
void List<T>::clear() {
    while (size) {
        popFront();
    }
}

/* This method given size of the list. */
template <typename T>
int List<T>::getsize() {
    return size;
}

/* This method shows an all elements of the list. */
template <typename T>
void List<T>::show() {
    int i = 0;
    Node<T> *temp = first;
    while (temp->ptr != nullptr) {
        std::cout << "[" << i << "]" << temp->data << std::endl;
        ++i;
        temp = temp->ptr;
    }
    std::cout << "[" << i << "]" << temp->data << std::endl;
}

/* This is destructor in List, that deleted all List ,when disappear object of List */
template <typename T>
List<T>::~List() {
    clear();
}