#include <iostream>

int mul(int a, int b) {
    if (a < 0 || b < 0) {
        throw "Arguments less then zero!";
    } else {
        return a * b;
    }
}

int main() {
    int a = 5;
    int b = -7;

    try {
        std::cout << mul(a, b) << "\n";
    } catch(const char *e) {
        std::cerr << e << "\n";
    }
    return 0;
}