#include <iostream>
#include <vector>

std::vector<int> vec(2, 1);

int f(int n) {
    if(n < vec.size()) {
        return vec[n];
    }

    int next = f(n - 1) + f(n - 2);
    vec.push_back(next);
    
    return next;
}

int main() {
    std::cout << "Fibonachi 8-th number is: " << f(8) << "\n";
    std::cout << "Fibonachi 10-th number is: " <<f(10) << "\n";

    return 0;
}