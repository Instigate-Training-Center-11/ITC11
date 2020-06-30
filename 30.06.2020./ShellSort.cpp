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

    /* display elements of array */    
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": " << arr[i] << endl;
    }
}

int shellSort(int arr[], int size) {
      
    /* we need to divide the array to parts */
    /* and to swap elemnets with diffrent indexes of interval */
    for (int interval = size / 2; interval >= 1; interval /= 2) {

        /* in the first step the interval and the j are equlas */ 
        for (int j = interval; j < size; j++) {         
            for (int i = j - interval; i >= 0 && arr[i + interval] > arr[i]; i -= interval) {

                /* if the element of first part is small then */
                /* element of second patr , we need not to swap */
                swap(arr[i + interval], arr[i]);                
            }
        }
    }
    return 0;
}

int main() {
    size = 6;
    int arr[size] = {7, 4, 10, 8, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    shellSort(arr, size);
    display(arr);
    cout << endl;
    return 0;
}