#include <iostream>
#include <ctime>
#include <chrono>
//#include <cstdlib>

void displayArray(int *, int);
void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int main() {
    int array[] = {95, 45, 48, -8, -25, 98, 1, 400085, 65, 478, 1, 7777};
    int n = sizeof(array) / sizeof(array[0]);

    // int n = 1000;                           // for a big array
    // int array[n];                           // that you seen
    // for (int i = 0; i < n; i++) {           // seed of marge sort
    //     array[i] = rand() % 10000 + 1;
    // }

    std::cout << "Our array:" << std::endl;
    displayArray(array, n);
    int start = clock();
    mergeSort(array, 0, n - 1);
    int end = clock();
    std::cout << std::endl;
    std::cout << "Our sorted array:" << std::endl;
    displayArray(array, n);

    std::cout << "The time when needed for MARGE sort (microseconds):  " << end - start << std::endl;

    return (0);
}

void displayArray(int *array, int n) {
    for(int i = 0; i < n; ++i) {
        std::cout << array[i] << '\t';
    }

    std::cout << std::endl;
}

void merge(int *array, int low, int mid, int high) {
    int tempArr[high + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= high) {
        (array[i] <= array[j]) ? tempArr[k++] = array[i++] : tempArr[k++] = array[j++];
    }

    while(i <= mid) {
        tempArr[k++] = array[i++];
    }

    while(j <= high) {
        tempArr[k++] = array[j++];
    }

    k--;
    while(k >= 0) {
        array[k + low] = tempArr[k];
        k--;
    }
}

void mergeSort(int *array, int low, int high) {
    int mid;
    if(low < high) {
        mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}
