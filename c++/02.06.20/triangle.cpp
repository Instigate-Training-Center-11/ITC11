#include <iostream>

/*Drawing triangle*/
void triangle(int row) {
    for (int i = 1; i <= row; i++) {
        // Print  spaces 
        for (int j = 1; j < i; j++) {
            std::cout << " ";
        }
        // Print hollow inverted triangle 
        for (int j = 1; j <= (row * 2 - (2 * i - 1)); j++) {
            if (i == 1 || j == 1 || j == (row * 2 - (2 * i - 1))) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int row = 0;
    /*Entered a number of rows for triangle*/
    while (row < 1) {
        std::cout << "Please enter a number of rows you want to see: " << std::endl;
        std::cin >> row;
        std::cout << "Rows: " << row << std::endl;
    }
    triangle(row);
    return 0;
}

