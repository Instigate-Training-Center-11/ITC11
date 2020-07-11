#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void sumZero(int *arr, int size);

void sortAndPrintZero(int *arr, int n) {
	int count = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}

			if(arr[j] == arr[j + 1]) {
				arr[j + 1] = 32767;
				++count;
			}
		}
	}
	
	int newSize = n - count;
	int a[newSize];
	int index = 0;
	for(int i = 0; i < newSize; ++i) {
		if(arr[i] != 32767) {
			a[index++] = arr[i];
		}
	}
	
	sumZero(a, newSize);
}

void sumZero(int *arr, int size) {
	for(int i = 0; i < size; ++i) {
		for(int j = i + 1; j < size; ++j) {
			for(int k = j + 1; k < size; ++k) {
				if(arr[i] + arr[j] + arr[k] == 0) {
					cout << arr[i] << '\t'<< arr[j] << '\t' << arr[k] << endl;
				}
			}
		}
	}
}

void toString(int *arr, int size) {
	for(int i = 0; i < size; ++i) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main() {
	int a[] = {-3, -1, -1, 0, 1, 1, 2};
	toString(a, 7);
	sortAndPrintZero(a, 7);
	return 0;
}

