#include <iostream>

#include "queue.h"
#include "my_exception.h"

#include "node.cpp"
#include "list.cpp"
#include "queue.cpp"

int main() {
    std::cout << std::endl << "----------------FOR LIST---------------" <<std::endl;
    List<int> list;
    list.pushFront(17);
    list.pushFront(18);
    list.pushFront(19);

    try {
        std::cerr << list[6] << std::endl;
    } catch (MyException e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cerr << list[2] << std::endl;
    } catch (MyException e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        list.insert(20, 2);
    } catch (MyException e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        list.insert(21, -5);
    } catch (MyException e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        list.remove(9);
    } catch (MyException e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        list.remove(2);
    } catch (MyException e) {
        std::cerr << e.what() << std::endl;
    }

    list.show();
    std::cout << std::endl;
    return 0;
}