#ifndef _VECTOR_H_
#define _VECTOR_H_
#include<iostream>
template <typename Type>

class MyVector {
    Type* arr;
    unsigned int size;
    unsigned int reserveSize;
    public:

    MyVector(void);
    MyVector(unsigned int constructor_size, Type value);
    MyVector(unsigned int vSize);
    ~MyVector(void);
    void shrinkToFit(void);
    void reserve (unsigned int res);
    bool empty(void) const;
    unsigned int sizeCapacity(void)const;
    unsigned int getSize(void) const;
    void PushBack(const Type& newelement);
    void popBack(void);
    void popFront(void);
    void print(void) const;
    Type* begin(void);
    Type back(void);

};

#include "vector.cpp"
#endif