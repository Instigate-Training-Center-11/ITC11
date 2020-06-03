#include <iostream>

unsigned long fact_iter(int, unsigned long);

unsigned long fact_rec(int);

int main() {
    int value = 0;
    unsigned long factorial = 1;

    while (value < 1) {
        std::cout << "Enter a positive integer: ";
        std::cin >> value;
    }

    std::cout << "Fact_iter(" << value << ") = " << fact_iter(value, factorial) << std::endl;
    std::cout << "Fact_rec(" << value << ") = " << fact_rec(value) << std::endl;

    return 0;
}

unsigned long fact_iter(int value, unsigned long factorial) {
    for (int i = 1; i <= value; ++i) {
        factorial *= i;
    }
    return factorial;
}

unsigned long fact_rec(int value) {
    if (value > 1) {
        return value * fact_rec(value - 1);
    } else {
        return 1;
    }
}