#include <iostream>

void merge(int*, int, int, int);
void mergeSort(int*, int, int);
void print(int*, int);

int main() {
    int arr[] = {45, 25, 5, 75, 15, 65, 55, 35};
    int size = sizeof(arr) / sizeof(arr[0]);
  
    std::cout << "Before merge sort: \t";
    print(arr, size);

    mergeSort(arr, 0, size - 1);
    std::cout << "After merge sort: \t";
    print(arr, size);

    return 0;   
}

void merge(int *arr, int left, int mid, int right) {
    int i;
    int j;
    int k;
    int leftSize;
    int rightSize;

    leftSize = mid - left + 1;
    rightSize = right - mid;

    int leftArr[leftSize];
    int raigthArr[rightSize];

    for (i = 0; i < leftSize; ++i) {
        leftArr[i] = arr[left + i];
    }

    for(j = 0; j < rightSize; ++j) {
        raigthArr[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while(i < leftSize && j < rightSize) {
        if(leftArr[i] <= raigthArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = raigthArr[j];
            ++j;
        }

        ++k;
    }

    while(i < leftSize) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    while(j < rightSize) {
        arr[k] = raigthArr[j];
        ++j;
        ++k;
    }
}

void mergeSort(int *arr, int left, int right) {
    int mid = 0;
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void print(int *arr, int size) {
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << "  ";
    }

    std::cout << "\n";
}