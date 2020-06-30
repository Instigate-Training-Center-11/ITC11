#ifndef _SORTING_ALGORITHM_HPP
#define _SORTING_ALGORITHM_HPP

#include <cstdlib>

/* Merge sort */

template<typename Type>
void sort(Type array[], int begin, int end, int mid);

template<typename Type>
void merge_sort(Type array[], int begin, int end);

/* Selection sort */

template<typename Type>
void selection_sort(Type array[], int size);

template<typename Type>
void print(Type array[], int size);

template<typename Type>
void random_array(Type array[], int size);

#include "sorting_algorithm.cpp"

#endif