#include <iostream>
#include <cmath>
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

int interpolation(int *arr, int size, int data) {
        //data = arr[0] + ((arr[1] - arr[0]) * index)
        int index = (data - arr[0]) / (arr[1] - arr[0]);
        if(arr[index] == data) {
                return index;
        }
}


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
        //int arr[] = {3, 4, 5, 6};
	while(true) {
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
	char ch;
	cout << endl << "Plesase input algoritm linear, binary, exponential, interpolation, jump or ternary (l,b,e,i,j or t): ";
	cin >> ch;
	switch(ch) {
		case 'l':
			cout << "index of " << value << " in your arr is " << linear(arr, size, value) << endl;
			break;
		case 'b':
			cout << "index of " << value << " in your arr is " << binary(arr, value, size - 1) << endl;
                        break;
                case 'e':
			cout << "index of " << value << " in your arr is " << exponential(arr, size, value) << endl;
                        break;
                case 'i':
			cout << "index of " << value << " in your arr is " << interpolation(arr, size, value) << endl;
                        break;
                case 'j':
			cout << "index of " << value << " in your arr is " << jump(arr, value, size - 1) << endl;
                        break;
                case 't':
			cout << "index of " << value << " in your arr is " << ternary(arr, value, size - 1) << endl;
                        break;

	}
	}

        //cout << "index of " << value << " in your arr is " << jump(arr, value, size - 1) << endl;
        return 0;
}


