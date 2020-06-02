#include <iostream>

int main() {

    /* The side of the triangle, which will be printed. */
    int number = 0;
    
    /* Enter the side of the triangle, until the entered number is greather, then one. */
    do {
        std::cout << "Enter the heigth: ";
        std::cin >> number;
    } while (number < 2);

    /* Implementation of printing a triangle whit the specified side. */
    for (int row = 1; row <= number; row++) {
        for (int col = 1; col <= number * 2 - 1; col++) {
            if (row == 1 && col % 2 == 1) {
                std::cout << '*';
            } else if (row == col) {
                std::cout << '*';
            } else if (row + col == 2 * number) {
                std::cout << '*';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << "\n";
    }
    return 0;
}