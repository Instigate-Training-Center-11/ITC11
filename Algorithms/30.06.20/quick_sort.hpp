#ifndef _QUICK_SORT_HPP
#define _QUICK_SORT_HPP

#include <cstdlib>

/* Quick sort */

template<typename Type>
void sort(Type array[], int begin, int end);

template<typename Type>
void swap(Type& first, Type& second);

template<typename Type>
void print(Type array[], int size);

template<typename Type>
void random_array(Type array[], int size);

#include "quick_sort.cpp"

#endif