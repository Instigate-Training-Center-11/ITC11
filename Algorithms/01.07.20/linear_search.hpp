#ifndef _LINEAR_SEARCH_HPP_
#define _LINEAR_SEARCH_HPP_

#include <iostream>

int linear_search(int array[], int value, int size) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == value) {
            return i;
        }
    }
    return -101;
}

#endif