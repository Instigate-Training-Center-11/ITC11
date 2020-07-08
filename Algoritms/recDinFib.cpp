#include <iostream>
#include <vector>
using namespace std;

vector<int> v(2, 1);

int fib(int index) {
	if(index < v.size()) {
		return v[index];
	}
	int f = fib(index - 1) + fib(index - 2);
	v.push_back(f);
	return f;
}

int main() {
	cout << fib(2) << endl;
	cout << fib(3) << endl;
	cout << fib(4) << endl;
	return 0;
}
