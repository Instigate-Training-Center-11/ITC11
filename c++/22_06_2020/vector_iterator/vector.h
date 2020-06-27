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

    private:

    friend class  MyVector;
    Type* pVector;

    public:

    Iterator(Type* pObject) : pVector(pObject) { }

    Iterator& operator+(unsigned int position) {
        while (position != 0) {
            if (*pVector == '\0') {
                std::cout << "You went too far !!!" << std::endl;
                return *this;
            }
            ++pVector;
            --position;
        }
        return *this;
    }

    Type operator*() {
        return *pVector;
    }

    Iterator& operator-(int position) {
        while (position != 0) {
            if (*pVector == '\0') {
                std::cout << "You went too far !!!" << std::endl;
                return *this;
            }
            --pVector;
            --position;
        }
        return *this;
    }

    bool operator!=(const Iterator& itr) const {
        return pVector != itr.pVector;
    }

    bool operator==(const Iterator& itr) const {
        return pVector == itr.pVector;
    }

    Iterator operator++(int) {
        Iterator temp = *this;
        pVector++;
        if (*pVector == '\0') {
            std::cout << "You went too far !!!" << std::endl;
            return *this;
        } else {
            return temp;
        }
    }

    Iterator operator--(int) {
        Iterator temp = *this;
        pVector--;
        if (*pVector == '\0') {
            std::cout << "You went too far !!!" << std::endl;
            return *this;
        } else {
            return temp;
        }
    }

    Iterator operator--(void) {
        pVector--;
        if (*pVector == '\0') {
            std::cout << "You went too far !!!" << std::endl;
            return nullptr;
        } else {
            return *this;
        }
    }

    Iterator operator++(void) {
        pVector++;
        if (*pVector == '\0') {
            std::cout << "You went too far !!!" << std::endl;
            return *this;
        } else {
            return nullptr;
        }
    }

};


    MyVector(unsigned int elementcount = 0 , Type value = 0);
    MyVector(MyVector<Type> &object);
    ~MyVector(void);
    /* Resizes the container so that it contains n elements.If n is smaller than the current container size,
     * the content is reduced to its first n elements, removing those beyond (and destroying them).
     * If n is greater than the current container size, the content is expanded by inserting at the end as many
     * elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val,
     * otherwise, they are value-initialized.If n is also greater than the current container capacity, an automatic
     * reallocation of the allocated storage space takes place. */
    void resize(unsigned int sizeVector, Type value = 0);
    /*  Assigns new contents to the container, replacing its current contents,
     * and modifying its size accordingly. */
    MyVector<Type>& operator= (MyVector<Type>& object);
    /* Returns a reference to the element at position index in the vector container. */
    Type& operator[](unsigned int index);
    /* Requests the container to reduce its capacity to fit its size. */
    void shrinkToFit(void);
    /* Requests that the vector capacity be at least enough to contain n elements.
     * If val is specified, the new elements are initialized as copies of res,
     * otherwise, they are value-initialized. */
    void reserve (unsigned int res);
    /* Returns whether the vector is empty (i.e. whether its size is 0). */
    bool empty(void) const;
    /* Returns the number of elements in the vector.
     * Member type sizeCapacity is an unsigned integral type. */
    unsigned int sizeCapacity(void)const;
    /* Returns the number of elements in the vector.
     * Member type size_type is an unsigned integral type. */
    unsigned int getSize(void) const;
    /* Adds a new element at the end of the vector, after its current last element. */
    void PushBack(const Type& newelement);
    /* Removes the last element in the vector, effectively reducing the container size by one.
    This destroys the removed element. */
    void popBack(void);
    void print(void) const;
    /* Returns an iterator pointing to the first element in the vector. */
    Type* begin(void);
    /* Returns an iterator referring to the past-the-end element in the vector container.*/
    Type* end(void);
};

#include "vector.cpp"
#endif