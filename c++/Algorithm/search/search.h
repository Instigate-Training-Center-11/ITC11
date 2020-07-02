#ifndef SEARCH_H
#define SEARCH_H

int getType(std::string str, int number);
void swap(int &a, int &b);
void print(int* arr, int size);
void printValue(int value, int valIndex);
int linearSearch(int *arr, int size, int value);
int binarySearch(int *arr, int first, int last, int value);
int jumpSearch(int *arr, int size, int value);
int interpolationSearch(int *arr, int size, int value);
int exponentialSearch(int *arr, int size, int value);
int ternarySearch(int *arr, int first, int last, int value);
void selectionSort(int *arr, int size);

#endif
