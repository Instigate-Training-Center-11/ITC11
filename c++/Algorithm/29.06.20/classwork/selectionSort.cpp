#include <iostream>
#include <ctime>
#include <chrono>

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void display(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
        std::cout << std::endl;
    }
}

void selectionSort(int *arr, int size) {
    int i;
    int j;
    int min;
    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[min])
                min = j;
                swap(arr[i], arr[min]);
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter elements:" << std::endl;
    for(int i = 0; i<n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Array before Sorting: ";
    display(arr, n);
    int start = clock();
    selectionSort(arr, n);
    int end = clock();
    std::cout << "Array after Sorting: ";
    display(arr, n);
    std::cout << "The time Insertion sort (microseconds):  " << end - start << std::endl;
    return 0;
}
