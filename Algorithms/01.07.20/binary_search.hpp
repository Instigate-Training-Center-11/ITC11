#ifndef _BINARY_SEARCH_HPP_
#define _BINARY_SEARCH_HPP_

#include <iostream>

int binary_search(int array[], int value, int end, int begin = 0) {
    --end;
    while (begin <= end) {
        int mid = begin + (end - begin) / 2;
        if (array[mid] == value) {
            return mid;
        }
        if (array[mid] > value) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }

    return -101;
}

#endif