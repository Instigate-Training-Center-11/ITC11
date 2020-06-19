#include <iostream>
#include "list.hpp"

int main() {
    List l;
    int num = 0;
    std::cout << "How elements do you want to push: ";
    std::cin >> num;
    for (int i = 0; i < num; i++) {
        l.push_back(i);
    }
    l.printf();
    std::cout << "Size = " << l.getSize() <<std::endl;
    std::cout << "After push_front" << std::endl;
    l.push_front(7);
    l.push_front(9);
    l.printf();

    std::cout << "After pop_front" << std::endl;
    l.pop_front();
    l.printf();

    std::cout << "After add element" << std::endl;
    l.add(8,2);
    l.printf();
    l.clear();
    return 0;
}

