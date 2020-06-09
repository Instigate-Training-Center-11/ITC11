#include <iostream>

int checkType(int input) {
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();

        std::cout << "Please enter an integer: ";
        std::cin >> input;
    }

    return input;
}

int main() {
    int arr[4] = {1, 2, 3, 4};
    int i = 0;
    std::cout << "Enter index of array you want to print: ";
    std::cin >> i;

    i = checkType(i);

    if (i >= 0 && i <4) {
        std::cout << "a[" << i << "] = " << arr[i] << std::endl;
    } else {
        std::cout << "Inputted index is out of the range!  a[3] = " << arr[3] << std::endl;
    }

    return 0;
}