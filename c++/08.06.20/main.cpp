#include <iostream>
#include "list.hpp"
#include "list.cpp"

int main() {
    List<int> l;
    int num = 0;
    std::cout << "How elements do you want to push: ";
    std::cin >> num;
    for (int i = 0; i < num; i++) {
        l.push_back(i);
    }
    l.printf();
    std::cout << "Size = " << l.getSize() <<std::endl;
    l.push_front(7);
    l.push_front(9);
    l.printf();
    l.pop_front();
    l.printf();
    l.add(8,2);
    l.printf();
    l.clear();

    List<double> l1;
    l.push_back(5.6);
    l1.push_back(1.2);
    l1.push_back(5.3);
    l1.push_back(1.4);
    l1.push_back(3.6);
    l1.push_back(4.9);
    l1.printf();
    l1.push_front(7.4);
    l1.push_front(9.5);
    l1.printf();
    l1.pop_front();
    l1.printf();
    l1.add(8.1,2);
    l1.printf();
    l1.clear();

    return 0;
}

