#include<iostream>
#include <vector>

std::vector<int> vector(2, 1);

int fib(unsigned int);

int main() {
    std::cout << fib(8) << std::endl;
    std::cout << fib(9) << std::endl;
    std::cout << fib(3) << std::endl;
    std::cout << fib(4) << std::endl;
    return 0;
}

int fib(unsigned int n) {
    if(n < vector.size()) {
        return vector[n];
    }

    int element = fib(n - 1) + fib(n - 2);
    vector.push_back(element);
    return element;
}