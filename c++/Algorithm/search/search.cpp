#include <iostream>
#include <cmath>
#include "search.h"

/*Checks input number is integer or symbol*/
int getType(std::string str, int number) {
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cerr << "ERROR: Faulty input! ";
        std::cout << "Enter integer number: ";
        std::cout << str;
        std::cin >> number;
    }

    return number;
}

/*      LINEAR SEARCH      */
/*Start from the leftmost element of array and one by one
 * compare value with each element of arrar*/
int linearSearch(int *arr, int size, int value) {
    for (int i = 0; i < size; ++i)
        if (arr[i] == value) {
            return i;
        }
    return -1;
}

/*      BINARY SEARCH      */
/* Search a sorted array by repeatedly dividing the search interval in half*/
int binarySearch(int *arr, int first, int last, int value) {
    int middle;
    if(first > last) {
        return -1;
    } else {
        middle = (first + last) / 2;
        if (arr[middle] > value) {
            binarySearch(arr, first, middle - 1, value);
        } else if (arr[middle] < value) {
            binarySearch(arr, middle + 1, last, value);
        } else {
            return middle;
        }
    }
}

/*      JUMP SEARCH      */
/*find the position of a searched value
 * in a sorted list by dividing the array
 * into several fixed-size blocks*/
int jumpSearch(int *arr, int size, int value) {
    int first = 0;
    int step = sqrt(size);
    while (arr[first] < value) {
        if (arr[step] > value && step >= size) {
            break;
        } else {
            first = step;
            step += sqrt(size);
        }
    }
    for (int i = first; i < step; i++) {
        if(arr[i] == value)
            return i;
    }
    return -1;
}

/*      INTERPOLATION SEARCH      */
/*interpolation search may go to different locations
 * according to the value of the key being searched*/
int interpolationSearch(int *arr, int size, int value) {
    int first = 0;
    int last = size - 1;
    int pos;
    while (first <= last && value >= arr[first] && value <= arr[last]) {
        pos = first + (((double)(last - first)/(arr[last]-arr[first])) * (value - arr[first]));

        if (arr[pos] == value) {
            return pos;
        }

        if (value > arr[pos]) {
            first = pos + 1;
        } else {
            last = pos-1;
        }
    }
    return -1;
}

/*      EXPONENTIAL SEARCH      */
/**/
int exponentialSearch(int *arr, int size, int value) {
    if (arr[0] == value) {
        return 0;
    }

    int i = 1;
    while (i < size && arr[i] <= value) {
        if (i > size) {
            return binarySearch(arr, i / 2, size, value);
        }
        return binarySearch(arr, i / 2, i, value);
    }
}

/*      TERNARY SEARCH      */
int ternarySearch(int *arr, int first, int last, int value) {
    while (first < last) {
        int mid1 = first + (last - first) / 3;
        int mid2 = last - (last - first) / 3;
        if (arr[mid1] == value) {
            return mid1;
        }
        if (arr[mid2] == value) {
            return mid2;
        }
        if (value < arr[mid1]) {
            last = mid1 - 1;
        } else if (value > arr[mid2]) {
            first = mid2 + 1;
        }
        return -1;
    }
}

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void print(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void printValue(int value, int valIndex) {
    if (valIndex != -1) {
        std::cout << "The index of " << value << " is: " << valIndex << std::endl;
    } else {
        std::cout << "Array does not contain element like " << value <<  std::endl;
    }
}

void selectionSort(int *arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
                swap(arr[i], arr[min]);
            }
        }
    }
}

