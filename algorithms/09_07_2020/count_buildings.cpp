#include<iostream>
#include <vector>

std::vector<int> vector(2, 1);

int fib(unsigned int);
int inputNumber();

int main() {
    std::cout << "Enter count of sections: " << std::endl;
    int n = inputNumber();
    std::cout << "The number of possible options: ";
    std::cout << fib(n + 1) * fib(n + 1) << std::endl;
    return 0;
}

/* This function inputed an integer number */
int inputNumber() {
    int intNumber = 0;
    std::cout << "Enter number: ";
    std::cin >> intNumber;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cout << "Enter only number: ";
        std::cin >> intNumber;
    }

    return intNumber;
}

/* this function counted n-th fibonachi number */
int fib(unsigned int n) {
    if(n < vector.size()) {
        return vector[n];
    }

    int element = fib(n - 1) + fib(n - 2);
    vector.push_back(element);
    return element;
}
