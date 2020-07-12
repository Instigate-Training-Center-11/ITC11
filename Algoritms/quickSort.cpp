#include <iostream>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp; 
}

int partition (int *arr, int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; ++j) {
		if (arr[j] < pivot) {
			swap(&arr[++i], &arr[j]);
        	}
	}

	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int high, int low = 0) {
	if (low < high) {
		int pivot = partition(arr, low, high);
		quickSort(arr, pivot - 1, low);
		quickSort(arr, high, pivot + 1);
	}
}

void printArray(int arr[], int size) {  
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}  

int main() {
	int arr[] = {0, 9, 3, 7, 6, 5};
	printArray(arr, 6);
	cout << endl;
	quickSort(arr, 6);
	printArray(arr, 6);
	return 0;
}
