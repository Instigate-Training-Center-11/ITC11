#include <iostream>

double checkType(double input) {
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();

        std::cout << "Please enter an integer: ";
        std::cin >> input;
    }

    return input;
}

int main() {
    double number1 = 0.0;
    double number2 = 0.0;
    double div = 0.0;


    std::cout << "Enter first number for division: ";
    std::cin >> number1;
    number1 = checkType(number1);

    std::cout << "Enter second number for division: ";
    std::cin >> number2;
    number2 = checkType(number2);

    if (0 != number2) {
        div = number1 / number2;
        std::cout << "Division of two inputted numbers is: " << number1 << " / " << number2 << " = " << div << std::endl;
    } else {
        do {
        std::cout << "WARNING! You can not divide by 0." << std::endl;
        std::cout << "\nTry aganin! Enter second number for division: ";
        std::cin >> number2;
        } while (0 == number2);
        std::cout << "Division of two inputted numbers is: " << number1 << " / " << number2 << " = " << number1/number2 << std::endl;
    }

    return 0;
}