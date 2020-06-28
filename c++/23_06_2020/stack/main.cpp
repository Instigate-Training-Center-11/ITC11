#include <iostream>
#include "stack.h"
#include "list.h"

// Run----> g++ -std==c++14 main.cpp
int main() {
    //Stack<int, MyVector<int>> stack(5,111);
    Stack<int, List<int>> stack(5,111);
    for (int i = 0; i < 5; ++i) {
        stack.push(i);
    }
    std::cout<<"Stack Size--------" << stack.size() << std::endl;
    while (!stack.empty()) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }

    return 0;
}