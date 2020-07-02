#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

/* function sorting algorithms,arguments arr(array), key-what we are looking for,
 * (start,end) -beginning and end of an array by index, returned key */
int ternarySearch(int* arr, int key, int start,int end);
int exponentialSearch(int* arr, int key, int start, int end);
int interpolationSearch (int* arr, int key, unsigned int size);
int jumpSearch(int* arr, int key, unsigned int size);
int linearSearch(int* arr, int key, unsigned int size);
int binarySearch(int* arr, int key, int left, int right);
void shellSort(int* array, unsigned int sizeArr);
void printArray(int* array,unsigned int size);
void swap(int& indexNumOne, int& indexNumTwo);
int* inputArray(unsigned int size);
int algorithm(int* arr, int choice, unsigned int size);


#endif