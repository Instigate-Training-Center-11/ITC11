#ifndef ITERATOR_H
#define ITERATOR_H

template <typename T>
class Iterator {
    public:
        Iterator();
        Iterator(T*);
        ~Iterator();
        Iterator& operator+(int);
        Iterator& operator-(int);
        Iterator* operator++(int);
        Iterator* operator++();
        Iterator* operator--(int);
        Iterator* operator--();
        T& operator*();
        Iterator<T>*& operator=(Iterator<T>*);
        Iterator<T>* operator=(T*);
        bool operator==(const Iterator& b) const;
        bool operator!=(const Iterator& b) const;
    private:
        T* ptr;
};

#endif