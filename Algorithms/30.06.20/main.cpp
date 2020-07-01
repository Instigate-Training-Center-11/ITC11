#include <iostream>
#include "quick_sort.hpp"

int main() {
    int size = 29;
    int array[size];

    random_array(array, size);

    std::cout << "Array = ";
    print(array, size);

    std::cout << std::endl;

    sort(array, 0, size);

    std::cout << "Sorted array = ";
    print(array, size);

    std::cout << std::endl;

    return 0;
}