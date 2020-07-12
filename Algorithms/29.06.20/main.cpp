#include <iostream>
#include <ctime>
#include "sorting_algorithm.hpp"

int main() {
    int size = 25;
    // int size = 10000;
    int array1[size];

    random_array(array1, size);

    srand(time(0));
    merge_sort(array1, 0, size - 1);

    print(array1, size);

    std::cout << std::endl;
    std::cout << "Runtime for merge_sort:\t\t" << clock() / 1000.0 << std::endl;

    int array2[size];

    random_array(array2, size);
    srand(time(0));
    selection_sort(array2, size);

    print(array2, size);

    std::cout << std::endl;
    std::cout << "Runtime for selection_sort:\t" << clock() / 1000.0 << std::endl;

    return 0;
}