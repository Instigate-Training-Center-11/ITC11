#include <iostream>
using namespace std;

int binary(int *arr, int data, int last, int first = 0) {
	if(arr[last] == data) {
		return last;
	}
	if(arr[first] == data) {
		return first;
	}
        int i = first + (((last + 1) - first) / 2);
	//cout << i;
        if(arr[i] == data) {
                return i;
        }
        if(data > arr[i]) {
                binary(arr, data, last, i);
        } else {
                binary(arr, data, i, first);
        }
}

int exponential(int *arr, int size, int data) {
	int i = 0;
	
	if(arr[i] == data) {
		return 0;
	}

	for(i = 1; i < size; i *= 2) {
		if(arr[i] == data) {
			return i;
		}
		if(arr[i] > data) {
			//cout << i << " " << size - 1 << endl;
			return binary(arr, data, size - 1, i - 1);
		}
	}
	// cout << i << " " << size - 1 << endl;

	return binary(arr, data, size - 1, i);
}

int main() {
        int arr[] = {1, 3, 5, 7, 9};
        cout << "index of 7 in {1, 3, 5, 7, 9} is " << exponential(arr, 5, 7) << endl;
        return 0;
}

