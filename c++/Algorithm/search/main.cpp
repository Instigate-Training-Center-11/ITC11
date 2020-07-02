#include <iostream>
#include "search.h"

int main() {
    int size = 0;
    std::string str1 = "How many elements would you like to enter?:";
    std::cout << str1;
    std::cin >> size;
    size = getType(str1, size);
    int arr[size];
    int el = 0;
    std::cout << "Enter Array elements: " << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> el;
        el = getType("array element: ", el);
        arr[i] = el;
    }

    std::cout << std::endl;
    int value = 0;
    std::cout << "Enter the element that you want to search:";
    std::string str2 = "value = ";
    std::cout << str2;
    std::cin >> value;
    value = getType(str2, value);
    std::cout << std::endl;

    int choice = 0;
    int valIndex = 0;
    while (choice != 7) {
       std::string str3 = "\nPlease, choose a searching algorithm you want to use: ";
       std::cout << str3;
       std::cin >> choice;
       choice = getType(str3, choice);
       std::cout << std::endl;

       switch(choice) {

           case 1:
               std::cout << "LINEAR SEARCH" << std::endl;
                valIndex = linearSearch(arr, size, value);
                printValue(value, valIndex);
                break;
            case 2:
                std::cout << "BINARY SEARCH" << std::endl;
                std::cout << "Array after sorting" << std::endl;
                selectionSort(arr, size);
                print(arr, size);
                valIndex = binarySearch(arr, 0, size - 1, value);
                printValue(value, valIndex);
                break;
            case 3:
                std::cout << "JUMP SEARCH" << std::endl;
                std::cout << "Array after sorting" << std::endl;
                selectionSort(arr, size);
                print(arr, size);
                valIndex = jumpSearch(arr, size, value);
                printValue(value, valIndex);
                break;
            case 4:
                std::cout << "INTERPOLATION SEARCH" << std::endl;
                std::cout << "Array after sorting" << std::endl;
                selectionSort(arr, size);
                print(arr, size);
                valIndex = interpolationSearch(arr, size, value);
                printValue(value, valIndex);
                break;
            case 5:
                std::cout << "EXPONENTIAL SEARCH" << std::endl;
                std::cout << "Array after sorting" << std::endl;
                selectionSort(arr, size);
                print(arr, size);
                valIndex = exponentialSearch(arr, size, value);
                printValue(value, valIndex);
                break;
            case 6:
                std::cout << "TERNARY SEARCH" << std::endl;
                std::cout << "Array after sorting" << std::endl;
                selectionSort(arr, size);
                print(arr, size);
                valIndex = ternarySearch(arr, 0, size - 1, value);
                printValue(value, valIndex);
                break;
            case 7:
                std::cout << "EXIT" << std::endl;
                break;
        }
    }
    return 0;
}

