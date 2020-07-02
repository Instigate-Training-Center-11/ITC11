#ifndef _JUMP_SEARCH_HPP_
#define _JUMP_SEARCH_HPP_

#include <math.h>
#include <iostream>
#include "linear_search.hpp"

int jump_search(int array[],int value, int size) {
    int step = (int)sqrt(size);
    int temp = step;
    int begin = 0;
    while (step < size) {
        if (value < array[step]) {
            if (step < size) {
                return begin + linear_search(&array[begin], value, step);
            }
            return begin + linear_search(&array[begin], value, size);
        } else {
            begin = step;
            step = step + temp;
        }
    }

    return -101;
}

#endif