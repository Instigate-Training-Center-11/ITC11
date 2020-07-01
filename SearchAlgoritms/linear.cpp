#include <iostream>
using namespace std;

int linear(int *arr, int size, int data) {
	int index = 0;
	for(int i = 0; i < size; ++i) {
		if(arr[i] == data) {
			index = i;
			break;
		}
	}
	return index;
}

int main() {
	int arr[] = {5, 4, 7};
	cout << "index of 7 in {5, 4, 7} is " << linear(arr, 3, 7) << endl;
	return 0;
}
