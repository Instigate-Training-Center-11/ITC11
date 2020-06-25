#include <iostream>
#include "stack.h"
#include "stack.cpp"
int main() {
    Stack<int> S;
    std::cout << "After push elements in stack" << std::endl;
    S.push(10);
    S.push(24);
    S.push(28);
    S.push(32);
    S.push(30);
    S.display();
    Stack<int> s(S);
    std::cout << "Copy constructor" << std::endl;
    s.display();
    std::cout << "Size = " << S.size() << std::endl;
    std::cout << "Top element = " << S.top() << std::endl;
    std::cout << "After pop element" << std::endl;
    S.pop();
    S.pop();
    S.display();

    return 0;
}

