#ifndef _ALGORITHM_HPP_
#define _ALGORITHM_HPP_

int jump_search(const int array[],int value, int size);
int exp_search(const int array[], int value, int size);
int linear_search(const int array[], int value, int size);
int interpol_search(const int arr[], int value, int size);
int binary_search(const int array[], int value, int end, int begin = 0);
int ternary_search(const int array[], int value, int end, int begin = 0);

#endif