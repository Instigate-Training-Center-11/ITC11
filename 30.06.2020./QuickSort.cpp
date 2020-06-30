#include <iostream>
using namespace std;

int size = 0;

/* create function for swap elements of array */
void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

/* create function for display elements of array */
void display(int arr[]) {
    cout << "Displaying elements: " << endl;
    /* display array elements */
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": " << arr[i] << endl;
    }
}
/* we have subunits for elements gretter of pivot and smaller of pivot */
/* for my realization I selected for pivot value the first element of array */
int subunit(int arr[], int left, int right) {
    int pivot = arr[left];
    int start = left;
    int end = right;

    /* we nned to increment from start element, while elements are small then pivot */
    /* and we need to decrement from end, while elements are greater, then pivot */
    while (start < end) {
        while (arr[start] <= pivot) {
            start++;
        }
        while (arr[end] > pivot) {
            end--;
        }
        if (start < end) {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[left], arr[end]);
    return end;
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int local = subunit(arr, left, right);
        quickSort(arr, left, local - 1);
        quickSort(arr, local + 1, right);
    }
}

int main() {
    size = 6;
    int arr[size] = {7, 4, 10, 8, 3, 1};
    quickSort(arr, arr[0], arr[size]);
    display(arr);
    cout << endl;
    return 0;
}