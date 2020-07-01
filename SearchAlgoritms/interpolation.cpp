#include <iostream>
using namespace std;

int interpolation(int *arr, int size, int data) {
	//data = arr[0] + ((arr[1] - arr[0]) * index)
	int index = (data - arr[0]) / (arr[1] - arr[0]);
	if(arr[index] == data) {
		return index;
	}
}

int main() {
        int arr[] = {1, 3, 5, 7, 9};
        cout << "index of 9 in {1, 3, 5, 7, 9} is " << interpolation(arr, 5, 9) << endl;
        return 0;
}

