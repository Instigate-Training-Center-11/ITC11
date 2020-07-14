#ifndef _IOSTREAM_
#define _IOSTREAM_
#include <iostream>
#include "vector.h"

template <typename Type>
MyVector<Type>::MyVector() {
    arr = new Type[0];
    arr = nullptr;
    this->size = 0;
    this->reserveSize = 20;
    std::cout << "default const\n";
}

template <typename Type>
MyVector<Type>::MyVector(unsigned int vSize) {
    try {
        this->size = vSize;
        arr = new Type[vSize];
	    for(int i = 0; i < vSize; ++i) {
	    	arr[i] = 0;
	    }
    } catch (const std::exception& e) {
        std::cerr << "Incorrect index!!!" << e.what() << std::endl;
        this->size = 0;
    }
    this->reserveSize = 0;
}
template <typename Type>
MyVector<Type>::MyVector(unsigned int vSize, Type value) {
    this->size = vSize;
    try {
        arr = new Type[vSize];
	    for(int i = 0; i < vSize ; ++i) {
	    	arr[i] = value;
	    }
    } catch (const std::exception& e) {
        std::cerr << "Incorrect index!!!" << e.what() << std::endl;
        this->size = 0;
    }
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
void MyVector<Type>::shrinkToFit(void) {
    if (0 == size) {
        std::cout << "Vector is empty" << std::endl;
    } else {
        Type* temp = new Type[size];
        for (int i = 0; i < size; ++i) {
            temp[i] = arr[i];
        }
        delete [] arr;
        arr = temp;
        temp = nullptr;
        reserveSize = size;
    }
}

template <typename Type>
void MyVector<Type>::reserve(unsigned int res) {
    try {
        if (res > this->size) {
            Type* temp = new Type [res];
            for (int i = 0; i < res; ++i) {
                if (i < this->size) {
                    temp[i] = arr[i];
                } else {
                    temp[i] = 0;
                }
            }
            delete [] arr;
            arr = temp;
            reserveSize = res;
            temp = nullptr;
        }
    } catch (const std::exception& e) {
        std::cerr << "Err negative argument " << e.what() << std::endl;
        this->size = 0;
    }
}

template <typename Type>
bool MyVector<Type>::empty(void) const {
    if (0 == this->size) {
        return true;
    } else {
        return false;
    }
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
void MyVector<Type>::PushBack(const Type& newelement) {
    if (0 == this->size) {
        Type* temp = new Type [reserveSize];
        temp[0] = newelement;
        delete [] arr;
        arr = temp;
    } else if (0 == reserveSize) {
        reserveSize = 20;
        Type* temp = new Type [size + reserveSize];
        for(int i = 0; i < size + reserveSize ; ++i) {
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
    if (0 != reserveSize) {
        ++size;
        --reserveSize;
    }
}

template <typename Type>
void MyVector<Type>::popBack(void) {
    if (0 == this->size) {
        std::cout << "Vector is empty" << std::endl;
    } else {
        --this->size;
        ++this->reserveSize;
    }
}

template <typename Type>
void MyVector<Type>::popFront(void) {
    for (int i = 0; i < this->size; ++i) {
        arr[i] = arr[i + 1];
    }
    --this->size;
    ++reserveSize;
}

template <typename Type>
Type MyVector<Type>::back(void) {
    return arr[size - 1];
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