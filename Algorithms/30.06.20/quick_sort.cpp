#include <cstdlib>
#include <iostream>

void swap(int& first, int& second) {
    int temp = first;
    first = second;
    second = temp;
}

void sort(int array[], int begin, int end) {
    int i = begin;
    int j = end;
    int pivot = array[end - 1];

    while (i <= j) {
        while (array[i] < pivot) {
            i++;
        }

        while (array[j] > pivot) {
            j--;
        }

        if (i <= j) {
        swap(array[i], array[j]);
            i++;
            j--;
        }
    }

    if (begin < j) {
        sort(array, begin, j);
    }

    if (i < end) {
        sort(array, i, end);
    }
}

void print(int array[], int size) {
	for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
}

void random_array(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		array[i] = rand() % 1000;
	}
}