#include <iostream>
#include "list.h"
#include "list.cpp"
#include "iterator.h"

int main() {
    List<int> l;
    int num = 0;
    std::cout << "How elements do you want to push: ";
    std::cin >> num;
    for (int i = 0; i < num; i++) {
        l.push_back(i);
    }
    l.print();
    std::cout << "After push_front" << std::endl;
    l.push_front(7);
    l.push_front(9);
    l.push_back(15);
    l.print();
    std::cout << "After pop_front" << std::endl;
    l.pop_front();
    l.push_back(5);
    l.print();
    std::cout << "After pop_back" << std::endl;
    l.pop_back();
    l.print();
    return 0;
}

