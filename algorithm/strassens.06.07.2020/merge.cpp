#include <iostream>

void mergeSortArray(int* arr, int left,int right);
void merge(int* arr, int left, int mid, int right);
void showArr(int* arr);

const int SIZEARR = 10;
int main() {
    int arr[SIZEARR];
    int i = 0;
    while (i < SIZEARR) {
        arr[i] = rand() % 100;
        ++i;
    }
    showArr(arr);
    if (SIZEARR > 1) {
        std::cout << "\nAfter using mergeSort algorithm\n\n";
        mergeSortArray(arr,0,SIZEARR - 1);
    }
    showArr(arr);

    return 0;
}

void mergeSortArray(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortArray(arr, left, mid);
        mergeSortArray(arr, mid + 1, right);
        merge(arr,left,mid,right);
    }
}

void showArr(int* arr) {
    int temp = 0;
    while (temp < SIZEARR) {
        std::cout<< "arr[" << temp << "] = " << arr[temp] << "\n";
        ++temp;
    }
}


void merge(int* arr, int left, int mid, int right) {

    unsigned int i = 0;
    unsigned int j = 0;
    int start = 0;

    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;

    int leftArray[sizeLeft];
    int rightArray[sizeRight];

    while (i < sizeLeft) {
        leftArray[i] = arr[left + i];
        ++i;
    }

    while (j < sizeRight) {
        rightArray[j] = arr[mid + 1 + j];
        ++j;
    }

    i = 0;
    j = 0;

    start = left;

    while (i < sizeLeft && j < sizeRight) {
        if (leftArray[i] <= rightArray[j]) {
            arr[start] = leftArray[i];
            ++i;
        } else {
            arr[start] = rightArray[j];
            ++j;
        }
        ++start;
    }

    while (i < sizeLeft) {
        arr[start] = leftArray[i];
        ++i;
        ++start;
    }

    while (j < sizeRight) {
        arr[start] = rightArray[j];
        ++j;
        ++start;
    }

}

