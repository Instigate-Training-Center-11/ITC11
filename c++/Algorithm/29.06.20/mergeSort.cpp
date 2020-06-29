#include <iostream>
#include <ctime>
#include <chrono>

void display(int *arr, int size);

void merge(int *arr, int left, int mid, int right);

void mergeSort(int *arr, int left, int right);

int main() {
    int num;
    std::cout << "Enter the number of elements: ";
    std::cin >> num;
    int arr[num];
    std::cout << "Enter elements:" << std::endl;
    for (int i = 0; i < num; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Array before Sorting: " << std::endl;
    display(arr, num);
    int start = clock();
    mergeSort(arr, 0, num - 1);
    int end = clock();
    std::cout << "Array after Sorting: " << std::endl;
    display(arr, num);
    std::cout << "The time MERGE sort (microseconds):  " << end - start << std::endl;
    return 0;
}

void display(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
        std::cout << std::endl;
    }
}

void merge(int *arr, int left, int mid, int right) {
    int lSize = mid - left + 1;
    int rSize = right - mid;
    int lArr[lSize];
    int rArr[rSize];
    int i;
    int j;
    int k;
    for (i = 0; i < lSize; ++i) {
        lArr[i] = arr[left + i];
    }

    for (j = 0; j < rSize; ++j) {
        rArr[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < lSize && j < rSize) {
        if (lArr[i] < rArr[j]) {
            arr[k] = lArr[i];
            i++;
        } else {
            arr[k] = rArr[j];
            j++;
        }
        k++;
    }

    while (i < lSize) {
        arr[k] = lArr[i];
        i++;
        k++;
    }

    while(j < rSize) {
        arr[k] = rArr[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int left, int right) {
    int mid;
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

