#include <iostream>

/* function declaration factorialR, recursive calculates and returns the factorialR of the passed number */
unsigned long long int factorialR(int number);

/* function declaration factorialP, positive calculates and returns the factorialP of the passed number */
unsigned long long int factorialP(int number);

int main() {
    int number = 0;

    do {
        std::cout << "input a positive number: ";
        std::cin.ignore(1000000,'\n');
        std::cin >> number;
        std::cin.clear();
    } while (number < 3 || std::cin.fail());

    std::cout << "\ncall factorialP function\n\n";
    std::cout << "input number = "<< number << "\nResult\nfactorial = " << factorialP(number) << "\n\n";
    std::cout << "call factorialR function\n\n";
    std::cout << "input number = "<< number << "\nResult\nfactorial = " << factorialR(number) << "\n\n";

    return 0;
}

/* implementation of the factorialR function, recursive calculates and returns the factorialR of the passed number */
unsigned long long int factorialR(int number) {
    if (number == 2) {
        return 2;
    }
    return number * factorialR(--number);
}

/* implementation of the factorialP function, positive calculates and returns the factorialP of the passed number */
unsigned long long int factorialP(int number) {
    unsigned long long int factorial = 1;
    for (int i = 2; i <= number; i++) {
        factorial *= i;
    }
    return factorial;
}