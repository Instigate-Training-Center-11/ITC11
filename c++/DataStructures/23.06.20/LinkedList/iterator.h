#include "list.h"

#ifndef ITERATOR_H
#define ITERATOR_H

template <typename T>
class List<T>::iterator {
    Node<T>* current;

    public:
    iterator(Node<T>* it) {
        this->current = it;
    }

    T& operator*() {
        return current->value;
    }

    bool operator==(const iterator& eq) const {
        return current == eq.current;
    }

    bool operator!=(const iterator& diff) const {
        return current != diff.current;
    }

    iterator& operator++() {
        if (current->next != NULL) {
            current = current->next;
        }
        return *this;
    }

    iterator& operator--() {
        if (current->next != NULL) {
            current = current->prev;
        }
        return *this;
    }

    iterator& operator++(int) {
        iterator tmp = *this;
        Node<T>* ptr;
        ptr = ptr->next;
        return tmp;
    }

    iterator& operator--(int) {
        iterator tmp = *this;
        Node<T>* ptr;
        ptr = ptr->prev;
        return tmp;
    }

};

#endif

