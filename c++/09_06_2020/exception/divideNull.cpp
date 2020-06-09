#include <iostream>
#include <typeinfo>

int foo(int number1, int number2) {

    if (0 == number2) {
        throw "Division by zero condition!";
    }
    return number1/number2;
}

int main() {

    int numberOne = 0;
    int numberTwo = 0;
    int exit = 1;
    int resolt = 0;
    while (exit) {
    std::cout << "Enter numberOne ";
    std::cin >> numberOne;
    std::cout << "Enter numberTwo ";
    std::cin >> numberTwo;
    try {
        resolt = foo(numberOne, numberTwo);
        std::cout << resolt << std::endl;
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
    std::cout << "exit Enter 0\ncontinue Enter any number\nEnter number";
    std::cin >> exit;
    }
    return 0;
}
