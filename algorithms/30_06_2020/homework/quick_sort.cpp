#include <iostream>

void displayArray(int *, int);
int partitionQuick (int *, int, int);
void quickSort (int *, int, int);
void swap(int &, int &);

int main() {

    int array[] = {15, 14, 12, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(array) / sizeof(array[0]);
    std::cout << "Our array:" << std::endl;
    displayArray(array, n);
    quickSort(array, 0, n);
    std::cout << std::endl;
    std::cout << "Our sorted array:" << std::endl;
    displayArray(array, n);
    return (0);
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void displayArray(int *array, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << '\t';
    }

    std::cout << std::endl;
}

int partitionQuick (int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
   	for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int low, int high) {
    if(low < high) {
	    int pos = partitionQuick(arr, low, high);
        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
    }
}