#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void bubble(int *arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}

			if(arr[j] == arr[j + 1]) {
				arr[j + 1] = 32767;
			}
		}
	}
}

void sumZero(int *arr, int size) {
	bubble(arr, size);
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
	int a[] = {-3, -1, 0, 1, 1, 2};
	toString(a, 6);
	sumZero(a, 6);
	return 0;
}

