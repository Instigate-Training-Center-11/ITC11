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

void count(int n) {
    std::cout << "The count possible ways: " << f(n + 1) * f(n + 1) << "\n";
}

int main() {
    int n = 5;

    count(n);

    return 0;
}