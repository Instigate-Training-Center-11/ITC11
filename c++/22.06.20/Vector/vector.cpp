#include <iostream>

#include "vector.h"

typedef unsigned int Size_type;

/* default constructor of vector class */
template <typename T>
vector<T>::vector() {
    arr = new int [0];
    Size = 1;
    current = 0;
}

/* copy constructor of vector class */
template <typename T>
vector<T>::vector(const vector& value) {
    this->current = value.current;
    this->arr = new T[value.current];
    for (int i = 0; i < value.current; ++i) {
        arr[i] = value.arr[i];
    }
}

/* destructor of vector class */
template <typename T>
vector<T>::~vector() {
    delete[] arr;
}

/* function will add elements in the end of the vector */
template <typename T>
void vector<T>::push_back(T data) {
    if (current == Size) {
        int* tmp = new int [2 * Size];
        for (int i = 0; i < Size; ++i) {
            tmp[i] = arr[i];
        }
        delete[] arr;
        Size *= 2;
        arr = tmp;
    }
    arr[current] = data;
    current++;
}

/* function will delete elements from the end of the vector */
template <typename T>
void vector<T>::pop_back() {
    --current;
}

/* function will return Size of the vector */
template <typename T>
Size_type vector<T>::size() const {
    return current;
}

/* function will return capacity of the vector */
template <typename T>
Size_type vector<T>::capacity() const {
    return Size;
}

/* function will check if the vector is empthy or not and send a msg*/
template <typename T>
bool vector<T>::empty() {
    if (0 == current) {
        std::cout << "Vector is empty!" << std::endl;
        return true;
    } else {
        std::cout << "Vector is not empty!" << std::endl;
        return false;
    }
}

/* function will reSize the vector*/
template <typename T>
void vector<T>::resize(size_type n, T value) {
    if (current >= n) {
        print();
    } else {
        for (int i = current; i < n; ++i) {
            push_back(value);
        }
    }
    current = n;
}

/* function will reserve memory location for vector*/
template <typename T>
void vector<T>::reserve(Size_type n) {
    if (n > Size) {
        int* tmp = new int [n];
        for (int i = 0; i < Size; ++i) {
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
        Size = n;
    }
}

/* function will reduce vector's capacity to fit its Size */
template <typename T>
void vector<T>::shrink_to_fit() {
    if (Size > current) {
        Size = current;
    }
}

/* function will print vector element */
template <typename T>
void vector<T>::print() {
    for (int i = 0; i < current; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

/* function will return vector element by given index*/
template <typename T>
T& vector<T>::operator[](int index) {
    return arr[index];
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() {
    return vector<T>::iterator(&arr[0]);
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
    return vector<T>::iterator(&arr[Size]);
}
