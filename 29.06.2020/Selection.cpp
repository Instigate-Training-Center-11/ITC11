#include <iostream>
using namespace std;

int size = 0;

/* create function for swap elements of array */
void swap (int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

/* create function for display elements of array */
void display (int arr[]) {
    cout << "Displaying elements: " << endl;
    /* display array elements */
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": " << arr[i] << endl;
    }
}

/* create function for sort elements of array */
void selectionSort (int arr[], int size) {
        int j = 0;
    /* if we have n elements in array, we need */
    /* do  n - 1 steps to pass array for selection sort */
    for (int i = 0; i < size - 1; i++) {
        /* we need for firs to find the minimum element in array */
        int min = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        /* swap minimum element with first big element in array */
        if (min != i) {
            swap(arr[i], arr[min]);
        }
    }
}

int main () {
    size = 6;
    int arr[size] = {7, 4, 10, 8, 3, 1};
    selectionSort(arr, size);
    display(arr);
    cout << endl;
    return 0;
}