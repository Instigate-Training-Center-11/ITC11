#include<iostream>
using namespace std;

int getUgly(int n) {
	int ugly[n];
	ugly[0] = 1;

	int i2 = 0;
	int i3 = 0;
	int i5 = 0;

	int nextOf2 = 2;
	int nextOf3 = 3;
	int nextOf5 = 5;
	int nextUglyNo = 1;
  
	for(int i = 1; i < n; ++i) {
		nextUglyNo = min(nextOf2, min(nextOf3, nextOf5)); 
		ugly[i] = nextUglyNo;

		if(nextUglyNo == nextOf2) {
			i2 += 1;
			nextOf2 = 2 * ugly[i2];
		}

		if(nextUglyNo == nextOf3) {
			i3 += 1;
			nextOf3 = 3 * ugly[i3];
		}

		if(nextUglyNo == nextOf5) {
			i5 += 1;
			nextOf5 = 5 * ugly[i5];
		}
	}
	return nextUglyNo;
}
  
int main() {
	int n = 10; 
	cout << getUgly(n) << endl; 
	return 0; 
}
