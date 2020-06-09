#include <iostream>
using namespace std;

void printValue(int arr[], int index) {
	try {
		if(index > ((sizeof(arr) / sizeof(int)) - 1) || index < 0 ) {
			throw -1;
	}
		cout << arr[index] << endl;
	} catch(int e) {
		cerr << "Exc" << endl;
	}
}

int baj(int a, int b) {
	try {
	if(0 == b) {
		throw -1;
	}
	return a / b;
	} catch(int e) {
		cerr << "Exception" << endl;
	}
}

void print(int a) {
	if(a < 0) {
		throw -1;
	}
	cout << a << endl;
}

int main() {
	int arr[] = {1, 2};
	printValue(arr, 3);
	baj(2, 0);
	try {
		print(-5);
	} catch(int e) {
		cout << "Catched exception" << endl;
	}
	return 0;
}
