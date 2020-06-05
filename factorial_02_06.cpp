#include <iostream>

//This is a recursive function that calculates factorual of the enter number. 
int recursive_func(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * recursive_func(n - 1);
    }
}

//This is the function with for loop that calculates factorial of the enter namber.
int func_with_for(int n) {
    int F = 1;
	for (int i = 2; i <= n; ++i) {
	    F = F * i;
	}
    return F;
}

//Enter number and Display factorial.
int main() {
    int n = 0;
    std::cout << "Enter any positive integer number: ";
    std::cin >> n;
    while (n < 1) {
        std::cout << "Invalite number, please enter positive integer number: ";
        std::cin >> n;
        std::cout << std::endl;
    }

    std::cout << "Calculate " << n << "'s factorial using recursive function: ";
    std::cout << recursive_func(n) << std::endl << std::endl;

    std::cout << "Calculate " << n << "'s factorial using function whit for loop: ";
    std::cout << func_with_for(n) << std::endl;
    system("pause");
    return 0;
}
