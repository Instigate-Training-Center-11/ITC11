#include "Vector.h"

#ifndef ITERATOR_H
#define ITERATOR_H

/* This is header file describing user-defined type iterator. */
template<typename T> 
class Vector<T>::iterator {
    private:
    T *curr;
    public:
        iterator(T *i) {
            this->curr = i;
        }

        T& operator*() {
            return *curr;
        }

        bool operator==(const iterator& eq) const {
            return *curr == *eq.curr;
        }

        bool operator!=(const iterator& ne) const {
            return *curr != *ne.curr;
        }

        iterator& operator++() {
            curr++;
            return *this;
        }

        iterator& operator--() {
            curr--;
            return *this;
        }

        iterator& operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        iterator& operator--(int) {
            iterator tmp = *this;
            --(*this);
            return tmp;
        }
};

#endif