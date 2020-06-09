#include <iostream>
#include <stdlib.h>

int arrL(int arr[5], int index) {
    for (int i = 0; i < 5; ++i) {
        arr[i] = rand() % 10;
    }

    if (index > sizeof(arr) / sizeof(arr[0])) {
        throw "Greate then length";
    } else {
        std::cout << "OK" << "\n";
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int index = 11;

    try {
        std::cout << arrL(arr, index) << "\n";
    } catch(const char *e) {
        std::cerr << e << "\n";
    }
    return 0;
}
