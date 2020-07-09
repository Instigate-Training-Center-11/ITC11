#include <iostream>
using namespace std;
	
     int func(int n) {
		if (n == 0)
			return 1;
		if (n == 1)
			return 2;
		
		return func(n-2) + func(n-1);
	}

	int countWays(int n) {
		int f = func(n);
		return f*f;
	}	
	
	int main() {
        int number;
        cout << "Which option do you want to count? Enter the number: ";
		cin >> number;
        cout << "You have " << countWays(number) << " options." << endl;
	}
