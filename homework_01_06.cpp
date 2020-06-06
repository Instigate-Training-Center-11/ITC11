#include <iostream>

//create a function that will find and return the minimum of 2 given numbers
int Min(int a, int b) {
    int min = a;
    if (a > b) {
        min = b;
    };
    return min;
}

//create a function that will find and return the maximum of 2 given numbers
int Max(int a, int b) {
    int max = a;
    if (a < b) {
        max = b;
    };
    return max;
}

//create a function that will calculate and return the sum of the 2 given numbers
int Sum(int a, int b) {
    int c = a + b;
    return c;
}

//call functions Sum, Min, Max by main
int main() {
    int a = 0;
    int b = 0;

    //request a user to insert two integer numbers
    std::cout << "Insert a: ";
    std::cin >> a;
    std::cout << "Insert b: ";
    std::cin >> b;

    //display the input numbers
    std::cout << "a: " << a << "\tb: " << b << std::endl;

    //display the Min/Max/Sum
    std::cout << "Min: " << Min(a, b) << std::endl;
    std::cout << "Max: " << Max(a, b) << std::endl;
    std::cout << "Sum: " << Sum(a, b) << std::endl;
    return 0;
}
