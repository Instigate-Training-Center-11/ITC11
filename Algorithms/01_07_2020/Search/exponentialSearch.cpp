#include <algorithm>
#include "binarySearch.cpp"

/* exponential Search */
int exponentialSearch(int *arr, int size, int element) {
    if (arr[0] == element) {
        return 0;
    }

    int i = 1;
    while (i < size && arr[i] <= element) {
        i = i * 2;
    }

    return binarySearch(arr, i / 2, std::min(i, size), element);
}