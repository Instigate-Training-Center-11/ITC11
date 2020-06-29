#include <iostream>
#include <ctime>
#include <chrono>

void display(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
        std::cout << std::endl;
    }
}

void insertionSort(int *arr, int size) {
    int tmp;
    int j;
    for (int i = 1; i < size ; ++i) {
        tmp = arr[i];
        j = i;

        while ((tmp < arr[j - 1]) && (j >= 0)) {
            arr[j] = arr[j - 1];
            j = j - 1;
        }

        arr[j]=tmp;
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter elements:" << std::endl;
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Array before Sorting" << std::endl;
    display(arr, n);
    int start = clock();
    insertionSort(arr, n);
    int end = clock();
    std::cout << "Array after Sorting" << std::endl;
    display(arr, n);
    std::cout << "The time Insertion sort (microseconds):  " << end - start << std::endl;
    return 0;
}

