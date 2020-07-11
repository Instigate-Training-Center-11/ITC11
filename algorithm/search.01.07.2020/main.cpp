#include "algorithm.h"
#include <iostream>
#include <exception>

enum Algorithm {LinearSearch, BinarySearch,
                JumpSearch, InterpolationSearch,
                ExponentialSearch, TernarySearch};

int main() {

    try {
    unsigned int sizeArray = 0;
        std::cout << "\t\tInput array size, please\nsizeArray = ";
        std::cin >> sizeArray;
        if (sizeArray != 0) {
            int* arr = inputArray(sizeArray);
            shellSort(arr,sizeArray);
            /* A function takes an argument enum i runs that algorithm */
            algorithm(arr,JumpSearch,sizeArray);
            printArray(arr,sizeArray);
            delete [] arr;
        }
    } catch (...) {
        std::cerr << "Abnormal termination\n";
    }
    return 0;
}