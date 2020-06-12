#include <iostream>
#include "list.hpp"

int main(){
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
    std::cout << "After add new element" << std::endl;
    l.add(8,2);
    l.printf();
    std::cout << "After asynAdd" << std::endl;
    l.asyncAdd(69, 0);
    l.asyncAdd(60, 1);
    l.asyncAdd(87, 2);
    l.asyncAdd(98, 3);
    l.printf();
    std::cout << "After asyncRemove" << std::endl;
    l.asyncRemove(2);
    l.printf();
    std::cout << "Element by index 2: " << l.getByIndex(2) << std::endl;
    std::cout << "Size: " << l.getSize() << std::endl;
    l.clear();
    return 0;
}

