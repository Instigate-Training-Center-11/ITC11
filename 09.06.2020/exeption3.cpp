#include <iostream>

double div(int var1, int var2) {
    if (0 == var2) {
        std::cerr << "\nOOPS... Smth went wrong!!!" << std::endl;
        throw -1;
    }
    std::cout << "Division: " << var1 / var2 << std::endl;
}

int main() {
    int number1 = 0;
    int number2 = 0;

    std::cout << "Enter first number for division: ";
    std::cin >> number1;

    std::cout << "Enter second number for division: ";
    std::cin >> number2;

    try {
        div(number1, number2);
    }
    catch (int e) {}

    return 0;
}
