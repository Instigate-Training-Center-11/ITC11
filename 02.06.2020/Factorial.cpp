#include <iostream>

/* check  whether input number is integer or not,
if it is not an integer ask user to enter a positive number,
if it is an integer then return it */
int checkType(int input) {
    while (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore();

        std::cout << "Please enter a positive number: ";
        std::cin >> input;
    }

    return input;
}

/* check whether input number is greater then 1,
if it is equal to 1 or less then 1 then ask user tu enter a positive number,
every time when user input new symbol check whether it is integer or not,
if input is a positive integer then return it */
int checkPositive(int n){
    n = checkType(n);

    while (n < 1) {
        std::cout << "Please enter a positive number:  ";
        std::cin >> n;

        n = checkType(n);
    }

    return n;
}

/* calculate factorial of inputted number by recursive method,
returning type of function is long which will allow to calculating more integers factorial */
long recursiveFactorial(int input) {
    if (input > 1) {
        return (input * recursiveFactorial(input - 1));
    } else {
        return 1;
    }
}

/* calculate factorial of inputted number by interative method,
returning type of function is long which will allow to calculating more integers factorial */
long interativeFactorial(int input) {
    long factorial = 1;

    while (input > 1) {
        factorial = factorial * input;
        input -= 1;
    }
    return factorial;
}

int main() {
    int number;

    std::cout << "Please, enter a positive number: ";
    std::cin >> number;

    number = checkPositive(number);

    std::cout << "Factorial of inputted number is: " << interativeFactorial(number) << "  //used the interative method" << std::endl;

    std::cout << "Factorial of inputted number is: " << recursiveFactorial(number) << "  //used the recursive method" << std::endl;

    return 0;
}