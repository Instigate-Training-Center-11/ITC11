#include <iostream>
#include "List.h"
#include "Queue.h"
#include "List.cpp"
#include "Queue.cpp"
#include "myException.h"

int main() {
    std::cout << "Create object from linked list" << "\n";
    Data::LinkedList<int> list;
    /* Insert element in list */
    list.insertElement(7, 0);
    list.insertElement(8, 0);

    try {
        list.insertElement(4, 0);
    } catch (MyException &e) {
        std::cout << e.what() << "\n";
    }
    try {
        list.insertElement(14, 10);
    } catch (MyException &e) {
        std::cout << e.what() << "\n";
    }    
    list.showList();

    /* Get element from list by index. */
    try {
        std::cout << "GET: " << list.getElement(1) << "\n";
    } catch (MyException &e) {
        std::cout << e.what() << "\n";
    }

    /* Remove element */
    try {
        list.removeElement(0);
    } catch (MyException &e) {
        std::cout << e.what() << "\n";
    }
    list.showList();

    return 0;
}