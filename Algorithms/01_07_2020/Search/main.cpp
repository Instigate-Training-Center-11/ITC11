#include <iostream>
#include "linerSearch.cpp"
#include "exponentialSearch.cpp"
#include "interpolationSearch.cpp"
#include "jumpSearch.cpp"
#include "ternarySearch.cpp"

/* Print founded element index. */
void print(int *arr, int size, int element) {
    int low = 0;
    int high = size - 1;
    int result = 0;
    int algorithmNum = 0;

    std::cin >> algorithmNum;

    switch (algorithmNum) {
        case 1:
            result = linerSearch(arr, size, element);
            break;
        case 2:
            result = exponentialSearch(arr, size, element);
            break;
        case 3:
            result = interpolationSearch(arr, size, element);
            break;
        case 4:
            result = jumpSearch(arr, size, element);
            break;
        case 5:
            result = ternarySearch(arr, low, high, element);
            break;
        case 6:
            result = binarySearch(arr, low, high, element);
            break;
        
        default:
            std::cout << "Not found algorithm for that number!" << "\n";
            break;
    }

    (result == -1) ? std::cout << "\nThe element " << element << " not found" << "\n"
                    : std::cout << "\nThe elements index is: " << result << "\n";
}

int validInput() {
    int num = 0;
    do {
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cout << "Enter only number array elements: ";
        std::cin >> num;
    } while (std::cin.fail());

    return num;
}

int *enterArr(int size) {
    int *arr = new int[size];
    for(int i = 0; i < size; i++) {
        arr[i] = validInput();
    }

    return arr;
}

int main() {
    /* Array size and searching element. */
    int size = 0;
    int element = 0;

    std::cout << "Enter the array Size: " << "\n";
    std::cin >> size;

    /* Array, in which will find the element index. */
    int *arr = enterArr(size);
    std::cout << "The inserted array is : " << "\n";
    for (int i = 0 ; i < size; ++i) {
        std::cout << arr[i] << "\t";
    }

    std::cout << "\n\nEnter the element value which index need to find: " << "\n";
    std::cin >> element;

    std::cout << "\nChoose the search algorithm: " << "\n";

    std::cout << "Enter 1 for linerSearch: " << "\n";
    std::cout << "Enter 2 for exponentialSearch: " << "\n";
    std::cout << "Enter 3 for interpolationSearch: " << "\n";
    std::cout << "Enter 4 for jumpSearch: " << "\n";
    std::cout << "Enter 5 for ternarySearch: " << "\n";
    std::cout << "Enter 6 for binarySearch: " << "\n";

    /* This function wil print the result of searching. */
    print(arr, size, element);

    return 0;
}