#include "vector.h"

#ifndef ITERATOR_H
#define ITERATOR_H

template <typename T>
class vector<T>::iterator {
    T* ptrPos;

    public:
    iterator(T* it) {
        this->ptrPos = it;
    }

    iterator& operator*() {
        return *ptrPos;
    }

    bool operator==(const iterator& eq) const {
        return *ptrPos == *eq.ptrPos;
    }

    bool operator!=(const iterator& diff) const {
        return *ptrPos != *diff.ptrPos;
    }

    iterator& operator++() {
        ptrPos++;
        return *this;
    }

    iterator& operator--() {
        ptrPos--;
        return *this;
    }

    iterator& operator++(int) {
        iterator tmp = *this;
        ++(*this);
        return tmp;
    }
};

#endif
