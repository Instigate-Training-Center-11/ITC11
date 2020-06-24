#include "List.h"

#ifndef ITERATOR_H
#define ITERATOR_H

/* This is header file describing user-defined type iterator. */
template<typename T> 
class List<T>::iterator {
    private:
        Node<T> *current;
    public:
        Node<T> *curr;
        iterator(Node<T> *pointer) {
            this->current = pointer;
        }

        iterator& operator++() {
            current = current->next;
            return *this;
        }

        iterator& operator--() {
            current = current->prev;
            return *this;
        }

        iterator& operator++(int) {
            iterator temp = *this;
            Node<T> *node;
            node = node->next;
            return temp;
        }

        iterator& operator--(int) {
            iterator temp = *this;
            Node<T> *node;
            node = node->prev;
            return temp;
        }

        T& operator*() {
            return current->data;
        }

        bool operator==(const iterator& eq) const {
            return current == eq.current;
        }

        bool operator!=(const iterator& ne) const {
            return current != ne.current;
        }
};

#endif