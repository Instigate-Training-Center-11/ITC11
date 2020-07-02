#ifndef _INTERPOLATION_SEARCH_HPP_
#define _INTERPOLATION_SEARCH_HPP_

int interpol_search(int arr[], int value, int size) {
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

#endif