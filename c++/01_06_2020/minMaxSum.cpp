#include <iostream>

/* Function that finds the smallest of the two numbers */
int min(int firstNum, int secondNum) {
    if (firstNum < secondNum) {
        return firstNum;
    } else {
        return secondNum;
    }
}

/* Function that finds the largest of the two numbers */
int max(int firstNum, int secondNum) {
    if (firstNum > secondNum) {
        return firstNum;
    } else {
        return secondNum;
    }
}

/* Function that calculates the sum of two numbers */
int sum (int firstNum, int secondNum) {
    return firstNum + secondNum;
}

int main() {
    int a = 0;
    int b = 0;

    std::cout << "Insert a: ";
    std::cin >> a;
    std::cout << "Insert b: ";
    std::cin >> b;

    std::cout << "a: " << a << "\t";
    std::cout << "b: " << b << std::endl;

    std::cout << "Min: " << min(a, b) << std::endl;
    std::cout << "Max: " << max(a, b) << std::endl;
    std::cout << "Sum: " << sum(a, b) << std::endl;

    return 0;
}