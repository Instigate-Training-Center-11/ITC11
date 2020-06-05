#include <iostream>

/* function to find factorial of given number by recursion */
int factorialRec(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorialRec(n - 1);
}
/* function to find factorial of given number without recursion */
int factorialWRec(int n) {
    int result = 1;
    for (double i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}
/* main function for displaying versions of outputs */
int main() {
    int num;
    std::cout << "Enter the positive number: ";
    std::cin >> num;
    /* check number: it will be positive */
    while ( num < 0 ) {
    std::cout << num << " will be positive number: " << std::endl;
    std::cin >> num;
    }        
    std::cout << "Factorial with recursion of "
              << num << " is " << factorialRec(num) << std::endl;
    std::cout << "Factorial without recursion of "
              << num << " is " << factorialWRec(num) << std::endl;
    return 0;
}
