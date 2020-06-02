#include <iostream>

int max(int firstNum, int secondNum) {
    /* This function will return the argument, that is larger. */
    if (firstNum > secondNum) {
        return firstNum;
    } else {
        return secondNum;
    }
}

int min(int firstNum, int secondNum) {
    /* This function will return the argument, that is smaller. */
    if (firstNum > secondNum) {
        return secondNum;
    } else {
        return firstNum;
    }
}

int sum(int firstNum, int secondNum) {
    /* This function will return the summa of arguments. */
    return firstNum + secondNum;
}

int main() {
    int a = 0;
    int b = 0;
    /* Insert the integer arguments. */
    std::cout << "Insert a: ";
    std::cin >> a;
    std::cout << "Insert b: ";
    std::cin >> b;
    /* Display the arguments. */
    std::cout << "a: " << a << "\t";
    std::cout << "b: " << b << std::endl;
    /* Display the results function. */
    std::cout << "Min: " << min(a, b) << std::endl;
    std::cout << "Max: " << max(a, b) << std::endl;
    std::cout << "Sum: " << sum(a, b) << std::endl;
    return 0;
}