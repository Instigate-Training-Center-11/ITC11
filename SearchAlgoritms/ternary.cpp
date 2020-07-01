#include <iostream>
using namespace std;

int ternary(int *arr, int data, int last, int first = 0) {
        if(arr[last] == data) {
                return last;
        }
        if(arr[first] == data) {
                return first;
        }

        int i = first + (((last + 1) - first) / 3);
	int j = last - (((last + 1) - first) / 3);
        if(arr[i] == data) {
                return i;
        }
	if(arr[j] == data) {
		return j;
	}
	if(data < arr[i] ) {
		return ternary(arr, data, i, first);
	} else if(data > arr[j]) {
                return ternary(arr, data, j, i);
        } else {
                return ternary(arr, data, last, j);
        }
}

int main() {
        int arr[] = {3, 4, 5, 6};
        cout << "index of 6 in {3, 4, 5, 6} is " << ternary(arr, 6, 3) << endl;
        return 0;
}
