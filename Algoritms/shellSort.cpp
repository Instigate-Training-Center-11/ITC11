#include <iostream>
using namespace std;

int iter(int count) {
	int itr = 0;
	while((count /= 2) != 1) {
		++itr;
	}
	return itr;
}

void insertSort(int *arr, int size) {
        for(int i = 1; i < size; i++) {
                if(arr[i] < arr[i - 1]) {
                        for(int j = 0; j < i; ++j) {
                                if(arr[i] < arr[j]) {
                                        int temp = arr[j];
                                        arr[j] = arr[i];
                                        	for(int k = i; k > j + 1; --k) {
                                                	arr[k] = arr[k - 1];
                                        	}
                                        arr[j + 1] = temp;
                                }
                        }
                }
        }
}


void shellSort(int *arr, int size) {
	int count = 2;
	int itr = iter(size);
	while(itr--) {
		int a = size / count;
		for(int i = 0; i < size / 2; ++i) {
			if(arr[size / 2 + 1] > arr[size / 2 + 1 - a]) {
				int temp = arr[size / 2 + 1];
				arr[size / 2 + 1] = arr[size / 2 + 1 - a];
				arr[size / 2 + 1 - a] = temp;
			}
		}
		count *= 2;	
	}

	insertSort(arr, size);
}

void toString(int *arr, int size) {
	for(int i = 0; i < size; ++i) {
		cout << arr[i] << '\t';
	}
	cout << endl;
}

int main() {
	int arr[] = {1, 5, 4, 2, 0};
	shellSort(arr, 5);
	toString(arr, 5);
	return 0;
}
