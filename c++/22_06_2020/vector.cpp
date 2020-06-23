#ifndef _IOSTREAM_
#define _IOSTREAM_
#include <iostream>
#include "vector.h"

template <typename Type>
MyVector<Type>::MyVector() {
    arr = new Type[0];
    arr = nullptr;
    this->size = 0;
    this->reserveSize = 10;
    std::cout << "default const\n";
}

template <typename Type>
MyVector<Type>::MyVector(unsigned int vSize) {
    try {
        this->size = vSize;
        arr = new Type[vSize + reserveSize];
	    	for(int i = 0; i < vSize + reserveSize; ++i){
	    		arr[i] = 0;
	    	}
    } catch (const std::exception& e) {
        std::cerr << "Incorrect index!!!" << e.what() << std::endl;
        this->size = 0;
    }
    this->reserveSize = this->size + 10;
}
template <typename Type>
MyVector<Type>::MyVector(unsigned int vSize, Type value) {
    try {
        this->size = vSize;
        arr = new Type[vSize + reserveSize];
	    	for(int i = 0; i < vSize + reserveSize; ++i){
	    		arr[i] = value;
	    	}
    } catch (const std::exception& e) {
        std::cerr << "Incorrect index!!!" << e.what() << std::endl;
        this->size = 0;
    }
    this->reserveSize = this->size + 10;
}

template <typename Type>
MyVector<Type>::~MyVector() {
    if (size == 0) {
        std::cout << "Vector is empty" << std::endl;
    }
    if (0 < size) {
        delete [] arr;
    }
    arr = nullptr;
}

template <typename Type>
unsigned int MyVector<Type>::sizeCapacity(void) const {
    return this->reserveSize;
}


template <typename Type>
unsigned int MyVector<Type>::getSize(void) const {
    return this->size;
}

template <typename Type>
void MyVector<Type>::PushBack(Type newelement) {
    if (0 == this->size) {
        Type* temp = new Type [reserveSize];
        temp[0] = newelement;
        delete [] arr;
        arr = temp;
    } else if (0 == reserveSize) {
        reserveSize = 10;
        Type* temp = new Type [size + reserveSize];
        for(int i = 0; i < size + reserveSize; ++i) {
            if (i < size) {
				temp[i] = arr[i];
            } else if (i == size) {
                temp[i] = newelement;
            } else {
                temp[i] = 0;
            }
		}
        delete [] arr;
        arr = temp;
    } else {
        arr[size] = newelement;
    }
    ++size;
    --reserveSize;
}

template <typename Type>
void MyVector<Type>::print(void) const{
    if (0 == this->size) {
        std::cout << "Vector is empty" << std::endl;
        return;
    }
    for (int i = 0; i < this->size; ++i) {
        std::cout << arr[i] << std::endl;
    }
}

#endif