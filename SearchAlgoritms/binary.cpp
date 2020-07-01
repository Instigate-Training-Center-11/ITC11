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
	if(arr[i] == data) {
		return i;
	}
	if(data > arr[i]) {
		binary(arr, data, last, i);
	} else {
		binary(arr, data, i, first);
	}
}

int main() {
        int arr[] = {3, 4, 5, 6};
        cout << "index of 5 in {3, 4, 5, 6} is " << binary(arr, 5, 3) << endl;
        return 0;
}

