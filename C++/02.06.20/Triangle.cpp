#include <iostream>

int main () {
    int n = 0;
    std::cout << "Please insert n: ";
    std::cin >> n;
    std::cout << std::endl;
    while ((std::cin.fail() | n < 2)) {
            std::cout << "Please insert positive number only: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> n;
    }

    char simvol = '*';
    char space = ' ';
    int start = 2;
    int finish = (n * 2) - 2;

    /* Print first line */
    for (int i = 0; i < n; ++i) {
        std::cout << simvol << space;
    }

    std::cout << std::endl;

    /* Print all lines  */
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < 2 * n; ++j) {
            if (j == start && start < n) {
                std::cout << simvol;
            } else if (j == finish && finish >= n) {
                std::cout << simvol;
            } else {
                std::cout << space;
            }
        }
        ++start;
        --finish;
        std::cout << std::endl;
    }

    return 0;
}