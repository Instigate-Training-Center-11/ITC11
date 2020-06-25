#ifndef _VECTOR_H_
#define _VECTOR_H_
#include<iostream>
template <typename Type>

class MyVector {
    Type* arr;
    unsigned int size;
    unsigned int reserveSize;
    public:
    class Iterator {
        Type* pObj;
        public:
        Iterator(Type* pObj) : pObj(pObj) { }

        Type operator*() {
            return *pObj;
        }

        friend std::ostream& operator<<(std::ostream& out, MyVector<Type>::Iterator& itObject) {
            out << itObject.pObj << std::endl;
            return out;
        }

        Iterator operator+(int value) {
            this->pObj+=value;
            return *this;
        }
        Iterator& operator++(void) {
            this->pObj = pObj + 1;
            return *this;
        }
        Iterator& operator--(void) {
            this->pObj = pObj - 1;
            return *this;
        }
        Iterator operator-(int value) {
            this->pObj-=value;
            return *this;
        }
        Iterator operator--(int value) {
            Type* temp = pObj;
            this->pObj = pObj - 1;
            return temp;
        }
        Iterator operator++(int value) {
            Type* temp = pObj;
            this->pObj = pObj + 1;
            return temp;
        }
    };

    MyVector(void);
    MyVector(unsigned int constructor_size, Type value);
    MyVector(unsigned int vSize);
    ~MyVector(void);
    Type* operator[] (unsigned int index);
    void shrinkToFit(void);
    void reserve (unsigned int res);
    bool empty(void) const;
    unsigned int sizeCapacity(void)const;
    unsigned int getSize(void) const;
    void PushBack(const Type& newelement);
    void popBack(void);
    void print(void) const;
    Type* begin(void);
    Type* end(void);
};

#include "vector.cpp"
#endif