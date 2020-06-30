#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void bubble(int *arr, int n) {
	int steps = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
				++steps;
			}
		}
	}
	cout << "bubble steps :" << steps << endl;
}

void insertSort(int *arr, int size) {
	int steps = 0;
        for(int i = 1; i < size; i++) {
                if(arr[i] < arr[i - 1]) {
                        for(int j = 0; j < i; ++j) {
                                if(arr[i] < arr[j]) {
                                        int temp = arr[j];
                                        arr[j] = arr[i];
                                                for(int k = i; k > j + 1; --k) {
							++steps;
                                                        arr[k] = arr[k - 1];
                                                }
                                        arr[j + 1] = temp;
					++steps;
                                }
                        }
                }
        }
	cout << "insert steps :" << steps << endl;
}

void merge(int *arr, int size) {
	int steps = 0;
	for(int i = 2; i <= size; i *= 2) {
		for(int k = 0; k < size; k += i) {
			for(int n = k; n < i - 1; ++n) {
				for(int m = k; m < i - n - 1; ++m) {
					if(arr[m] > arr[m + 1]) {
						++steps;
						swap(arr[m], arr[m + 1]);
					}
				}
			}
		}
	}
	cout << "steps for merge : " << steps << endl;
}

void toString(int *arr, int size) {
	for(int i = 0; i < size; ++i) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main() {
	int arr[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5};
	int arr1[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5};
	int arr2[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5};
	insertSort(arr2, 16);
	toString(arr2, 16);
	merge(arr, 16);
	toString(arr, 16);
	bubble(arr1, 16);
	toString(arr1, 16);
	return 0;
}
