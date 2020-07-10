#include <iostream>
using namespace std;

void git(char* f, char *s, int sizeA, int sizeB) {
	cout << "First :" << f << endl;
	cout << "Second :" << s << endl;
	char *a = f;
	char *b = s;
	bool bo = true;
	int ia = 0;
	int ib = 0;
	for(int i = ia; i < sizeA; ++i) {
		for(int j = ib; j < sizeB; ++j) {
			if(a[i] == b[j]) {
				for(int n = ia; n < i; ++n) {
					cout << '-' << a[n];
				}

				for(int m = ib; m < j; ++m) {
					cout << '+' << b[m];
				}
				cout << a[i];
				ia = i + 1;
				ib = j + 1;
				bo = false;
				break;
			}
		}

		/*if(bo == false) {
			break;
		}*/
	}

	for(int n = ia; n < sizeA; ++n) {
		cout << '-' << a[n];
	}

	for(int m = ib; m < sizeB; ++m) {
		cout << '+' << b[m];
	}
	cout << endl;
}

int main() {
	git("abcd", "xybc", 4, 4);
	return 0;
}
