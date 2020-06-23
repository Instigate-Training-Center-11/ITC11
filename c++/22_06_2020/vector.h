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
    unsigned int sizeCapacity(void)const;
    unsigned int getSize(void) const;
    void PushBack(Type newelement);
    void print(void) const;
};

#include "vector.cpp"
#endif