#include <iostream>
#include <ctime>
#include <stdlib.h>

void merge(int *arr, int left, int mid, int right) {
    int i;
    int j;
    int k;
    int leftSize;
    int rightSize;
    /* Left subArray size. */
    leftSize = mid - left + 1;
    /* Rigt subArray size. */
    rightSize = right - mid;
    int leftArr[leftSize];
    int raigthArr[rightSize];

    /* Fill left subArray. */
    for (i = 0; i < leftSize; ++i) {
        leftArr[i] = arr[left + i];
    }
    /* Fill right subArray. */
    for(j = 0; j < rightSize; ++j) {
        raigthArr[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    /* Marge the tmp arrays. */
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

/* Merge sort. */
void mergeSort(int *arr, int left, int right) {
    int mid;
    if(left < right) {
        int mid = left + (right - left) / 2;
        /* Sort left ang rigt subArrays with mergeSort function. */
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/* Insertion sort. */
void insertionSort(int *arr, int length) {
    if(length > 1) {
        for(int i = 1; i < length; ++i) {
            int j = i;
            int tmp = arr[i];
            
            while(j > 0 && arr[j - 1] > tmp) {
                arr[j] = arr[j - 1];
                --j;
            }

            arr[j] = tmp;
        }
    }
}

void selectionSort(int *arr, int length) {
    int tmp;
    int min;

    for (int i = 0; i < length; ++i) {
        min = i;
        for (int j = i + 1; j < length; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        if (min != i) {
            tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
}

void print(int *arr, int size) {
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int arr[] = {8, 4, 1, 9, 6, 7, 55, 0, -1, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
  
    std::cout << "Array before any sorting: ";
    print(arr, size);

    /* Measure Merge sort execution time */
    mergeSort(arr, 0, size - 1);
    std::cout << "Array after Merge Sort: ";
    print(arr, size);

    /* Use this large array to see Execution time. */
    int *ar = new int;
    for (int i = 0; i < 1000; ++i) {
        ar[i] = rand() % 100 + 1;
    }

    int t1 = std::clock();
    mergeSort(ar, 0, 999);
    // selectionSort(ar, 1000);
    // insertionSort(ar, 1000);
    int t2 = std::clock();

    std::cout << "\nExecution time is: " << t2 - t1 << "\n";

    return 0;   
}