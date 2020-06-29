#include <iostream>
#include<ctime>

/* Combine two arrays array[left->mid] and array[mid + 1->right] */
void merge(int* array, int left, int mid, int right);
/* split the array into two equal parts so far there is nothing to split */
void mergeSortArray(int* array, int left, int right);
/* initialize the array with random values  */
void initializeArray(int* array,unsigned int size);
/* function print array */
void printArray(int* arr,unsigned int size);



int main() {

    unsigned int start_time =  clock();
    unsigned int sizeArray = 1000;
    int* arr = new int[sizeArray];

    initializeArray(arr,sizeArray);
    std::cout << "\t\tPrinting array without sorting\n";
    printArray(arr,sizeArray);
    std::cout << "\t\tCall function merge sort\n";
    mergeSortArray(arr, 0, sizeArray - 1);
    std::cout << "\t\tPrinting array after sorting\n";
    printArray(arr,sizeArray);
    unsigned int end_time = clock();
    std::cout << "\nruntime = " << clock()/1000.0 << " ms" << std::endl;
    return 0;
}


void mergeSortArray(int* array, int left, int right) {
    if (left < right) {
        unsigned int mid = left + (right - left) / 2;
        mergeSortArray(array, left, mid);
        mergeSortArray(array, mid + 1, right);
        merge(array,left,mid,right);
    }
}

void merge(int* array, int left, int mid, int right) {
    unsigned int i = 0;
    unsigned int j = 0;
    int begin = 0;

    int sizeLeftArray = mid - left + 1;
    int sizeRingArray = right - mid;

    int leftArray[sizeLeftArray];
    int rightArray[sizeRingArray];

    while (i < sizeLeftArray) {
        leftArray[i] = array[left + i];
        ++i;
    }

    while (j < sizeRingArray) {
        rightArray[j] = array[mid + 1 + j];
        ++j;
    }

    i = 0;
    j = 0;
    begin = left;

    while (i < sizeLeftArray && j < sizeRingArray) {
        if (leftArray[i] <= rightArray[j]) {
            array[begin] = leftArray[i];
            ++i;
        } else {
            array[begin] = rightArray[j];
            ++j;
        }
        ++begin;
    }

    while (i < sizeLeftArray) {
        array[begin] = leftArray[i];
        ++i;
        ++begin;
    }

    while (j < sizeRingArray) {
        array[begin] = rightArray[j];
        ++j;
        ++begin;
    }
}

void initializeArray(int* array,unsigned int size) {
    unsigned int i = 0;
    while (i < size) {
        array[i] = rand() % 100 -10000000;
        ++i;
    }

}

void printArray(int* array,unsigned int size){
    unsigned int i = 0;
    while (i < size) {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
        ++i;
    }

}
