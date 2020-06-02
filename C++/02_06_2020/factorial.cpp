#include <iostream>

long double factorialRecursia(int number);
long double factorialLoop(int number);

int main() {

    /* The number, for which we will count the factorial using recursia. */
    int number = 0;

    /* Enter a positive integer number. */
    do {
        std::cout << "Enter the number: ";
        std::cin >> number;
    } while (number < 0);

    /* Output of factorial with recursive path */
    std::cout << "Recursive factorial for number "
        << number << " = "
        << factorialRecursia(number) << "\n";

    /* Output of factorial with Iteration path */
    std::cout << "Iteration factorial for number "
        << number << " = "
        << factorialLoop(number) << "\n";
    return 0;
}

/* A function, that calculates the factorial using recursia. */
long double factorialRecursia(int number) {
    if(number < 0) {
        return 0;
    }
    if (number == 0) {
        return 1;
    } else {
        return number * factorialRecursia(number - 1);
    }
}

/* A function, that calculates the factorial using 'for' loop. */
long double factorialLoop(int number) {
    int result = 1;
    int i = 0;
    for (i = 2; i <= number; i++) {
        result *= i;
    }
    return result;
}