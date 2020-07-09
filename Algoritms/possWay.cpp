#include <iostream>
#include <vector>
using namespace std;

vector<int> v(2, 1);

int fib(int index) {
	int size = v.size();
	int iter = index - size;
	if(index < size) {
		return v[index];
	}
	for(int i = 0; i <= iter; ++i) {
		v.push_back(v[v.size() - 1] + v[v.size() - 2]);
	}
	return v[index];
}

int posWay(int n) {
	int c = fib(n + 1);
	return c * c;
}

int main() {
	cout << posWay(1) << endl;
	cout << posWay(2) << endl;
	cout << posWay(3) << endl;
	return 0;
}
