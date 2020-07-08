#include<iostream>
#include <vector>

std::vector<int> vector(2, 1);

int fib(unsigned int);

int main() {
    std::cout << fib(4) << std::endl;
    std::cout << fib(12) << std::endl;
    std::cout << fib(11) << std::endl;
    return 0;
}

int fib(unsigned int n) {
    if(n < vector.size()) {
        return vector[n];
    }

    if(n > vector.size()) {
        int size = vector.size();
        for(int i = size; i <= n; i++) {
            vector.push_back(vector[i - 1] + vector[i - 2]);
        }
        return vector[n];
    }
}