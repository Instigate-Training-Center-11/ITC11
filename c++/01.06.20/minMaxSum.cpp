#include <iostream>

/*Find a minimum number*/
int min(int num1, int num2) {
    if (num1 < num2) {
        return num1;
    } else {
        return num2;
    }
}

/*Find a maximum number*/
int max(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

/*Find a sum of two numbers*/
int sum(int num1, int num2) {
    return num1 + num2;
}

int main() {
    int num1 = 0;
    int num2 = 0;
    /*Request a user to insert two integer numbers*/
    std::cout << "Insert the first integer number: ";
    std::cin >> num1;
    std::cout << "Insert the second integer number: ";
    std::cin >> num2;
    std::cout << "Num1: " << num1 << std::endl;
    std::cout << "Num2: " << num2 << std::endl;

    /*Call the functions*/
    int m = min(num1, num2);
    int n = max(num1, num2);
    int s = sum(num1, num2);
    std::cout << "Min: " << m << std::endl;
    std::cout << "Max: " << n << std::endl;
    std::cout << "Sum: " << s << std::endl;
    return 0;
}

