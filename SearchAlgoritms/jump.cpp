#include <iostream>
#include <cmath>
using namespace std;

int jump(int *arr, int data, int last, int first = 0) {
	for(int i = first; i < last; i += sqrt(last - first)) {
		if(arr[i] == data) {
			return i;
		}
		if(arr[i] > data) {
			jump(arr, data, i, i - 1);
		}
	}
}

int main() {
        //int arr[] = {3, 4, 5, 6};
	int size;
	cout << "size :";
	cin >> size;
	cout << endl;
	int arr[size];
	for(int i = 0; i < size; ++i) {
		cin >> arr[i];
	}
	int value;
	cout << endl << "cin value :";
	cin >> value;
	cout << endl;

        cout << "index of " << value << " in your arr is " << jump(arr, value, size - 1) << endl;
        return 0;
}


