#include <iostream>

/* 
    This function takes a number as an argument,
    recursive calculates the factorial of that number,
    and returns it.
*/
int factorial(int number) {
    if (number < 2) {
        return 1;
    } else {
        return number * factorial(number - 1);
    }
}

/* 
    This function takes a number as an argument,
    interactive calculates the factorial of that number,
    and returns it.
*/
int factLoop(int number) {
    int mult = 1;
    for (int i = 1; i <= number; i++) {
        mult *= i;
    }
    return mult;
}

int main() {
    int digit = 0;

    /* Input the unsigned number */
    do {
        std::cout << "Please enter unsigned number: ";
        std::cin >> digit;
    } while (digit < 0);

    /* Output number of factorial */
    std::cout << "Recursive:\t" << factorial(digit) << std::endl;
    std::cout << "Interactive:\t" << factLoop(digit) << std::endl;
    
    return 0;
}