#include <iostream>
using namespace std;

void reverse(string& str) {
	int length = str.length();
	char temp = '\0';
	for(int i = 0; i < length / 2; i++) {
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
	}
}

int main() {
	string str = "";
	getline(cin, str);
	reverse(str);
	cout << str << endl;
	return 0;
}
