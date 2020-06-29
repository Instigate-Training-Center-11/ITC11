#include <iostream>
using namespace std;

int size = 0;

/* create function for display elements of array */
void display(int arr[]) {
    cout << "Displaying elements: " << endl;
    /* display array elements */
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": " << arr[i] << endl;
    }
}

/* create function for sort elements of array */
void selectionSort(int arr[], int size) {
    /* we need start our steps from 1st index */
    /* because we have the sorted and unsorted parts of array */
    /* and in the first step the sorted part is the [0] element */
    for (int i = 1; i < size; i++) {
        /* we need get into temp the first element of unsorted part of array */
        /* and to compare him with elements of second sorted part of array */
        /* comparing starts in the last element of the first sort part */
        /* so we will to pass with decrement */
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main() {
    size = 6;
    int arr[size] = { 10, 8, 3, 1, 7, 4 };
    selectionSort(arr, size);
    display(arr);
    cout << endl;
    return 0;
}
