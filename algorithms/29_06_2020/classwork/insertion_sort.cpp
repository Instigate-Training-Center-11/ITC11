#include <iostream>
#include <algorithm>

int displayArray(int *, int);
void insertionSort(int *, int);

int main() {
    int array[10] = { 2,1,7,4,3,5,9,6,8,0 };
    unsigned int size = sizeof(array)/sizeof(int);
    displayArray(array, size);
    insertionSort(array, size);
    displayArray(array, size);
}

void insertionSort(int *arr, int size) {
    int i, j, tmp;
    for (i = 1; i < size; i++) {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

int displayArray(int *arr, int size) {
    for(int i=0; i < size; i++) {
        std::cout << arr[i] << '\t';
    }

    std::cout << std::endl;
}