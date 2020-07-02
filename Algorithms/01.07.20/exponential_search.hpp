#ifndef _EXPONENTIAL_SEARCH_HPP_
#define _EXPONENTIAL_SEARCH_HPP_

#include "binary_search.hpp"

int exp_search(int array[],int value, int size) {
    if (array[0] == value) {
        return 0;
    }
    int count = 1;
    for (count; count < size && array[count] <= value; count *= 2) { };
    if (count < size) {
        return binary_search(array, value, count, count / 2);
    } else {
        return binary_search(array, value, size, count / 2);
    }
}

#endif