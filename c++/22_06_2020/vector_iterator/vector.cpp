#ifndef _IOSTREAM_
#define _IOSTREAM_
#include <iostream>
#include "vector.h"

template <typename Type>
void MyVector<Type>::resize(unsigned int sizeVector, Type value) {
    if (sizeVector > reserveSize) {
        Type* tempArr = new Type[2 * sizeVector];
        for (unsigned int i = 0; i < 2 * sizeVector; ++i) {
            if (i < size) {
                tempArr[i] = arr[i];
            } else if (i >= size && i < sizeVector) {
                tempArr[i] = value;
            } else {
                tempArr[i] = 0;
            }
        }
        delete [] arr;
        arr = tempArr;
        this->size = sizeVector;
        this->reserveSize = sizeVector;
        return;
    }

    if (sizeVector > size) {
        for (unsigned int i = 0; i < sizeVector; ++i) {
            PushBack(value);
        }
        return;
    }

    if (sizeVector < size) {
        Type* tempArr = new Type[sizeVector];
        for (unsigned int i = 0; i < sizeVector; ++i) {
            tempArr[i] = arr[i];
        }
        delete [] arr;
        arr = tempArr;
        this->size = sizeVector;
        return;
    }

}

template <typename Type>
MyVector<Type>::MyVector(unsigned int elementcount, Type value) {
    if (elementcount == 0) {
        arr = new Type[0];
        arr = nullptr;
        this->size = 0;
        this->reserveSize = 20;
    } else {
        this->size = elementcount;
        this->reserveSize = 0;
        arr = new Type[elementcount];
	    for(int i = 0; i < elementcount ; ++i) {
	    	arr[i] = value;
	    }
    }
}

template <typename Type>
MyVector<Type>::MyVector(MyVector<Type> &object) {
    *this = object;
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
Type& MyVector<Type>::operator[](unsigned int index) {
    if (index > size) {
        std::cout << "ERR Invalid index !!! size = " << size << " arr[size - 1] = ";
        return arr[size - 1];
    }
    return arr[index];
}

template <typename Type>
MyVector<Type>& MyVector<Type>::operator=(MyVector<Type>&  object) {
    this->size = object.getSize();
    this->reserveSize = object.sizeCapacity();
    arr = new Type[reserveSize];
    for (unsigned int i = 0; i < size; ++i) {
        if (i < size) {
            arr[i] = object[i];
        } else {
            PushBack(0);
        }
    }
    return *this;
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
Type* MyVector<Type>::begin(void) {
    return arr;
}

template <typename Type>
Type* MyVector<Type>::end(void) {
    return &arr[size - 1];
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