#include <iostream>

unsigned long fact_iter(int);

unsigned long fact_rec(int);

int main() {
    int value = 0;
    std::cout << "Please insert value: ";
    std::cin >> value;
    std::cout << std::endl;
    while ((std::cin.fail() | value < 1)) {
        std::cout << "Please insert positive number only: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> value;
    }

    std::cout << "Fact_iter(" << value << ") = " << fact_iter(value) << std::endl;
    std::cout << "Fact_rec(" << value << ") = " << fact_rec(value) << std::endl;

    return 0;
}

unsigned long fact_iter(int value) {
    int fact = 1;
    for (int i = 1; i <= value; ++i) {
        fact *= i;
    }
    return fact;
}

unsigned long fact_rec(int value) {
    if (value > 1) {
        return value * fact_rec(value - 1);
    } else {
        return 1;
    }
}