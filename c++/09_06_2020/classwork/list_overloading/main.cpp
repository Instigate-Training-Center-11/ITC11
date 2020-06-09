#include <iostream>
#include "list.h"

int main() {
    /* Adding elements from the beginning of the list and by given index and prints list. */
    List list;
    list.pushFront(1);
    list.pushFront(10);
    list.pushFront(100);
    list.insert(50, 0);
    list.insert(24, 3);
    list.pushFront(19);
    list.pushFront(110);
    list.pushFront(1);

    std::cout << list;

    return 0;
}
