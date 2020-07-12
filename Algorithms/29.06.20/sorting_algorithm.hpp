#ifndef _SORTING_ALGORITHM_HPP
#define _SORTING_ALGORITHM_HPP

/* Merge sort */

void sort(int array[], int begin, int end, int mid);

void merge_sort(int array[], int begin, int end);

/* Selection sort */

void selection_sort(int array[], int size);

void print(int array[], int size);

void random_array(int array[], int size);

#endif