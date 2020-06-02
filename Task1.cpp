#include <iostream>

/* check whether input number is greater then 1 */
int checkPositive(int number){
    while(number < 2) {
        std::cout << "Enter n: ";
        std::cin >> number;
    }
}

/* check is a function which will check whether input is integer or not */
int checkType(int input) {
    while(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore();

        std::cout << "Enter n: ";
        std::cin >> input;
    }

    input = checkPositive(input);
    return input;
}

int main() {
    int n = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    std::cout << "Enter n: ";
    std::cin >> n;

    n = checkType(n);

/* print first line of geographical shape */
    for (int i = 0; i < (2 * n - 1); i++) {
        if ((i % 2) == 0) {
            std::cout << "*";
        }
        else {
            std::cout << " ";
        }
    }

std::cout << std::endl;

for (int j = 0; j < (n - 1); j++) {
    for(int k = 0; k <= j; k++) {
    std::cout << " ";
    }

    std::cout << "*";

    for (int i = (j + 1); i < (2 * (n - 2) - j); i++) {
        while(i<(2 * (n - 2) - j)) {
            std::cout << " ";
            i++;
        }

        std::cout << "*" << std::endl;
    }
}

    std::cout << std::endl;
    return 0;
}
