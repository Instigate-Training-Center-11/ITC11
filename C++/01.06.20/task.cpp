#include <iostream>

/* This function return minimum for the two input numbers */
int min(int first, int second);

/* This function return maximum for the two input numbers */
int max(int first, int second);

/* This function return summary for the two input numbers */
int sum(int first, int second);

int main() {
    int first_value = 0;
    int second_value = 0;

    std::cout << "Please enter the first value: ";
    std::cin >> first_value;
    std::cout << std::endl;
    std::cout << "Please enter the second value: ";
    std::cin >> second_value;
    std::cout << std::endl;

    std::cout << "First value: " << first_value << std::endl;
    std::cout << "Second value: " << second_value << std::endl << std::endl;

    if (first_value == second_value) {
        /* Equality test */
        std::cout << "first and second values are equal" << std::endl;
        std::cout << "Sum: " << sum(first_value, second_value) << std::endl;
    } else {
        std::cout << "Min: " << min(first_value, second_value) << std::endl;
        std::cout << "Max: " << max(first_value, second_value) << std::endl;
        std::cout << "Sum: " << sum(first_value, second_value) << std::endl;
    }

    return 0;
}

int min(int first, int second) {
    return (first < second) ? first : second;
}

int max(int first, int second) {
    return (first > second) ? first : second;
}

int sum(int first, int second) {
    return first + second;
}