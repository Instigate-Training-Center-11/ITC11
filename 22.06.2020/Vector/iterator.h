#include "vector.h"

#ifndef ITERATOR_H
#define ITERATOR_H


/* following is the nested class of the vector class */
template <typename T>
class vector<T>::iterator
{
    T* ptr;

    public:
        iterator(T* it)
        {
            this->ptr = it;
        }

        iterator& operator*()
        {
            return *ptr;
        }

        bool operator==(const iterator& equal) const
        {
            return *ptr == *equal.ptr;
        }

        bool operator!=(const iterator& different) const
        {
            return *ptr != *different.ptr;
        }

        iterator& operator++()
        {
            ptr++;
            return *this;
        }

        iterator& operator--()
        {
            ptr--;
            return *this;
        }

        iterator& operator++(int)
        {
            iterator temp = *this;
            ++(*this);
            return temp;
        }

        iterator& operator--(int)
        {
            iterator temp = *this;
            --(*this);
            return temp;
        }
};
#endif