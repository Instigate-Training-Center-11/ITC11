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

void shellSort(int *arr, int size) {
    int mid = size / 2;
    while (mid > 0) {
        for (int i = mid; i < size; ++i) {
            for (int j = i; j >= mid && arr[j] < arr[j - mid]; j = j - mid) {
                swap(arr[j], arr[j - mid]);
            }
        }
        mid /= 2;
    }   
}

int main() {
    int arr[] = {8, 4, 1, 9, 6, 7, 55, 0, -1, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Array before any sorting: \t";
    print(arr, size);

    shellSort(arr, size);
    std::cout << "Array after Shell Sort: \t";
    print(arr, size);

    return 0;
}