#include <iostream>
#include <vector>

int min(int, int);
int min(int, int, int);
int findUglyNumber(int);
int inputNumber();

int main() {
    std::cout << "Enter number of ugly number: " << std::endl;
    int number = inputNumber();
    std::cout << number << " - th ugly number is ";
    std::cout << findUglyNumber(number) << std::endl;
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

/* This function counts the minimum of 2 numbers */
int min(int number1, int number2) {
    return (number1 < number2) ? number1 : number2;
}

/* This function counts the minimum of 3 numbers */
int min(int num1, int num2, int num3) {
    return min(min(num1, num2), num3);
}

/* This function found the n-th ugly number */
int findUglyNumber(int n) {
    int i = 0;
    int j = 0;
    int k = 0;
    std::vector<int> vector(1, 1);
    while(vector.size() < n) {
        int current = min(vector[i] * 2, vector[j] * 3, vector[k] * 5);
        if(current == vector[i] * 2) {
            ++i;
        }

        if(current == vector[j] * 3) {
            ++j;
        }

        if(current == vector[k] * 5) {
            ++k;
        }

        vector.push_back(current);
    }

    return vector.back();
}
