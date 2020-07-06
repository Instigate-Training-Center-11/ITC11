#include <iostream>

void displayArray(int *, int);
void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int main() {
    int array[] = {95, 45, 48, -8, -25, 98, 1, 400085, 65, 478, 1, 7777};
    int n = sizeof(array) / sizeof(array[0]);
    displayArray(array, n);
    mergeSort(array, 0, n - 1);
    displayArray(array, n);
    return 0;
}

void displayArray(int *array, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << '\t';
    }

    std::cout << std::endl;
}

void merge(int *array, int low, int mid, int high) {
    int newArr[high + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= high) {
        (array[i] <= array[j]) ? newArr[k++] = array[i++] : newArr[k++] = array[j++];
    }

    while (i <= mid) {
        newArr[k++] = array[i++];
    }

    while (j <= high) {
        newArr[k++] = array[j++];
    }

    k--;
    while (0 <= k) {
        array[k + low] = newArr[k];
        k--;
    }
}

void mergeSort(int *array, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}