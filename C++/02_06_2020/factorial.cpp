#include <iostream>
using namespace std;

long recursiveFactorial(int a) {
        if(a == 1) {
                return 1;
        }
        return a * recursiveFactorial(a - 1);
}


long iterativeFactorial(int a) {
        long fact = 1;
        while(a > 1) {
                fact *= a;
                --a;
        }
        return fact;
}


void factorial() {
	char methodOfCalculate = '\0';
	int number = 0;

	cout << "Please input positive number : ";
	cin >> number;

	if(number < 1) {
		cout << "Please input correct positive number!" << endl;
		factorial();
	}

	cout << "How do you want to calculate? With recursive or iterative functions f/i : ";
	cin >> methodOfCalculate;
	
	if(methodOfCalculate == 'f') {
		cout << number << "! = "<< recursiveFactorial(number) << endl;
	} else if(methodOfCalculate == 'i') {
		cout << number << "! = "<< iterativeFactorial(number) << endl;
	}

	factorial();
}


int main() {
        factorial();
	return 0;
}
