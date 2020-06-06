#include <iostream>
#include "list.hpp"

int main() {
    List list1(5, 7);
    List list2(12, 21);
    list1.print();
    list2.print();
    list1.push_back(777);
    list2.push_front(777);
    std::cout << "Max value in list1: " << list1.list_max() << std::endl;
    std::cout << "Min value in list1: " << list1.list_min() << std::endl;
    std::cout << "list size: " << list1.get_size() << std::endl;
    std::cout << "list size: " << list2.get_size() << std::endl;
    std::cout << "get at index = " << list1.get_at_index(11) << std::endl;
    std::cout << "get at index = " << list2.get_at_index(0) << std::endl;
    list1.reverse();
    list1.pop_back();
    list2.pop_front();
    list1.print();
    list2.print();

    return 0;
}