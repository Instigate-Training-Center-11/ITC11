#include <iostream>
#include <stdlib.h>

/*
    This function prints an equilateral triangle with stars.
    The function gets an argument - the count of '*' characters.
    This function will print a uniform triangle.
*/

void triangle(int count) {
    for (int i = 1; i <= count; ++i) {
        for (int j = 1; j <= count * 2 - 1; ++j) {
            if ((i == 1 && j % 2 == 1) || i == j || i + j == 2 * count) {
                std::cout << '*';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int countStar = 0;
    do {
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cout << "Enter n: ";
        std::cin >> countStar;
    } while (countStar < 2 || std::cin.fail());

    triangle(countStar);

    return 0;
}