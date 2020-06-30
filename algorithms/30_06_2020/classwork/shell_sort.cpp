#include <iostream>

void swap(int &, int &);
void shellSort(int *, int);
int displayArray(int *, int);

int main() {
    int array[13] = {13,12,11,10,9,8,7,6,5,4,3,2,1};
    size_t size = sizeof(array)/sizeof(int);
    displayArray( array, size );
    shellSort( array, size );
    displayArray( array, size );
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void shellSort(int *arr, int size) {
    for (int i = size / 2; i > 0; i /= 2) {
        for (int j = i; j < size; j++) {
            int k = j;
            while (arr[k] < arr[k - i] && k >= i) {
                swap(arr[k], arr[k - i]);
                k -= i;
            }
        }
    }

}

int displayArray(int *arr, int size) {
    for( int i=0; i<size; i++ ) {
        std::cout << arr[i] << '\t';
    }

    std::cout << std::endl;
}