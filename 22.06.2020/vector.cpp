#include <iostream>

#include "vector.h"

typedef unsigned int size_type;


/* default constructor of vector class */
template <typename T>
vector<T>::vector()
{
    arr = new int [0];
    length = 1;
    current = 0;
}

/* copy constructor of vector class */
template <typename T>
vector<T>::vector(const vector& value)
{
    this->current = value.current;
    this->arr = new T[value.current];
    for (int i = 0; i < value.current; ++i)
    {
        arr[i] = value.arr[i];
    }
}

/* destructor of vector class */
template <typename T>
vector<T>::~vector()
{
    delete[] arr;
}

/* following is a member function of vector class,
function will add elements in the end of the vector */
template <typename T>
void vector<T>::push_back(T data)
{
    if (current == length)
    {
        int* temp = new int [2 * length];
        for (int i = 0; i < length; ++i)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        length *= 2;
        arr = temp;
    }
    arr[current] = data;
    current++;
}

/* following is a member function of vector class,
function will delete elements from the end of the vector */
template <typename T>
void vector<T>::pop_back()
{
    --current;
}

/* following is a member function of vector class,
function will return size of the vector */
template <typename T>
size_type vector<T>::size() const
{
    return current;
}

/* following is a member function of vector class,
function will return capacity of the vector */
template <typename T>
size_type vector<T>::capacity() const
{
    return length;
}

/* following is a member function of vector class,
function will check if the vector is empthy or not and send a msg*/
template <typename T>
bool vector<T>::empty()
{
    if (0 == current)
    {
        std::cout << "Vector is empty!" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Vector is not empty!" << std::endl;
        return false;
    }
}

/* following is a member function of vector class,
function will resize the vector*/
template <typename T>
void vector<T>::resize(size_type n, T value)
{
    if (current >= n)
    {
        print();
    }
    else
    {
        for (int i = current; i < n; ++i)
        {
            push_back(value);
        }
    }
    
    current = n;
}

/* following is a member function of vector class,
function will reserve memory location for vector*/
template <typename T>
void vector<T>::reserve(size_type n)
{
    if (n > length)
    {
        int* temp = new int [n];
        for (int i = 0; i < length; ++i)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        length = n;
    }
}

/* following is a member function of the vector class,
function will reduce vector's capacity to fit its size */
template <typename T>
void vector<T>::shrink_to_fit()
{
    if (length > current)
    {
        length = current;
    }
}

/* following is a member function of the vector class,
function will print vector element */
template <typename T>
void vector<T>::print()
{
    for (int i = 0; i < current; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

/* following is a member function of the vector class,
function will return vector element by given index*/
template <typename T>
T& vector<T>::operator[](int index)
{
    return arr[index];
}

template <typename T>
typename vector<T>::iterator vector<T>::begin()
{
    return vector<T>::iterator(&arr[0]);
}

template <typename T>
typename vector<T>::iterator vector<T>::end()
{
    return vector<T>::iterator(&arr[length]);
}