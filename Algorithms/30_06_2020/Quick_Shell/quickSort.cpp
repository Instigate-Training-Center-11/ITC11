#include <iostream>

void swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void print(int *arr, int size) {
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << "  ";
    }

    std::cout << "\n";
}

void quickSort(int *arr, int lowIndex, int highIndex) {
    int i = lowIndex;
    int j = highIndex;
    int pivot = arr[j];

    while (i <= j) {
        while (arr[i] < pivot) {
            ++i;
        }
        
        while (arr[j] > pivot) {
            --j;
        }
            
        if (i <= j) {
            swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }

    if (j > lowIndex) {
        quickSort(arr, lowIndex, j);
    }

    if (i < highIndex) {
        quickSort(arr, i, highIndex);
    }
}

int main() {
    int arr[] = {8, 4, 1, 9, 6, 7, 55, 0, -1, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
  
    std::cout << "Array before any sorting: \t";
    print(arr, size);

    quickSort(arr, 0, size - 1);
    std::cout << "Array after Quick Sort: \t";
    print(arr, size);

    return 0;
}