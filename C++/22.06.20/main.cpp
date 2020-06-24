#include <iostream>
#include "vector.hpp"

int main() {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.print();
    Vector<int>::Iterator it = vec.begin();
    std::cout << *it << std::endl;
    std::cout << *(it + 5);
    return 0;
}