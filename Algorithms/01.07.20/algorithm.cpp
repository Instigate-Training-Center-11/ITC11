#include <math.h>
#include "algorithm.hpp"

int binary_search(const int array[], int value, int end, int begin) {
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

int linear_search(const int array[], int value, int size) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == value) {
            return i;
        }
    }
    return -101;
}

int jump_search(const int array[],int value, int size) {
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

int exp_search(const int array[], int value, int size) {
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

int ternary_search(const int array[], int value, int end, int begin) {
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

int interpol_search(const int arr[], int value, int size) {
	int begin = 0;
    int end = (--size);

	while (begin <= end && value >= arr[begin] && value <= arr[end]) {
		int pos = begin + (((float)(end - begin) / (arr[end] - arr[begin])) * (value - arr[begin]));

		if (arr[pos] == value) {
			return pos;
        }
		if (arr[pos] < value) {
			begin = pos + 1;
        } else {
			end = pos - 1;
        }
	}
	return -101;
}