#include<iostream>

//print a triangle with asterisks;
int main() {
    int n = 0;
    std::cout  << "Enter N: ";
    std::cin >> n;
	while (n < 2) {
        std::cout << "Invalit number, It must be a positive integer number, greater than or equal to 2. Try again: ";
        std::cin >> n;
        std::cout << std::endl;
    }

    for (int i = n; i >= 1; i--) {
        if (i == n) {
            for (int j = 1; j <= i; j++) {
                std::cout << "* ";
            }
        } else if (i == 1) {
            for (int j = 1; j <= n - 1; j++) {
                std::cout << " ";
            }
            std::cout << "*";
        } else {
            for (int j = n - i; j >= 1; j--) {
                std::cout << " ";
            }
            std::cout << "*";
            for (int j = n - i - 1; j <= i + n - 5; j++) {
                std::cout << " ";
            }
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    //this command used in windows for run the program and pause it.
    system("pause");
    return 0;
}