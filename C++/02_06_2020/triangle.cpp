#include <iostream>
using namespace std;

void displayTriangle() {
	int count = 0;
	cout << "Please input length : ";
	cin >> count;
	if(count < 1) {
		cerr << "Please input correct length!";
		displayTriangle();
	}
	int countOfSpaces = 1;
	for(int i = count; i > 0; --i) {
		cout << endl;
		countOfSpaces = count - i;
		while(countOfSpaces  > 0) {
			cout << "  ";
			--countOfSpaces ;
		}
		
		if(i == count) {
			for(int k = 0; k < count; ++k) {
				cout << " *  ";
			}
			continue;
		}

		for(int j = i; j > 0; --j) {
			if(j == i || j == 1) {
				cout << " *  ";
			} else {
				cout << "    ";
			}
		}
	}
	cout << endl;
	displayTriangle();
}

int main() {
	displayTriangle();
	return 0;
}
