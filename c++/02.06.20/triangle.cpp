#include <iostream>

/* Checks input number is integer or symbol */
int type (int num) {
    std::cout << "Please enter a number of rows you want to see: ";
    std::cin >> num;
    while (std::cin.fail() || num < 2) {
        std::cout << "ERROR: Faulty input! Try again!" << std::endl;
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cout << "Enter a positive number: ";
        std::cin >> num;
    }
    return num;
}

/*Drawing triangle*/
void triangle (int row) {
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j < i; j++) {
            std::cout << " ";
        }
        /*The sides of triangle*/
        for (int j = i; j <= 2 * row - 1; j++) {
            if ((i == 1 && j % 2 == 1) || j == i || i + j == 2 * row) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main () {
    int row = 0;
    /*Entered a number of rows for triangle*/
    int number = type(row);
    std::cout << "Rows: " << number << std::endl;
    triangle(number);
    return 0;
}

