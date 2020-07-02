#ifndef _TERNARY_SEARCH_HPP_
#define _TERNARY_SEARCH_HPP_

int ternary_search(int array[], int value, int end, int begin = 0) {
    while (begin <= end) {
        int mid1 = begin + (end - begin) / 3;
        int mid2 = end - (end - begin) / 3;

        if (array[mid1] == value) {
            return mid1;
        }

        if (array[mid2] == value) {
            return mid2;
        }

        if (array[mid1] > value) {
            end = mid1 - 1;
        } else if (array[mid2] < value) {
            begin = mid2 + 1;
        } else {
            end = mid2 -1;
            begin = mid1 + 1;
        }
    }

    return -101;
}

#endif