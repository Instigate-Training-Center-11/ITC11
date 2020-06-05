#include <iostream>
#include "list.h"

int main() {
    /* Adding elements from the beginning of the list and by given index and prints list. */
    List list;
    list.pushFront(1);
    list.pushFront(10);
    list.pushFront(100);
    list.insert(50, 0);
    list.insert(24,3);
    list.show();
    std::cout << "Size: " << list.getsize() << std::endl;

    /* We delete items from the list, as well as from this item that we select and prints list. */
    list.popFront();
    list.remove(3);
    list.show();
    std::cout << "Size: " << list.getsize() << std::endl;

    /* Use the loop to go through the entire list and print all the elements of this list. */
    for (int i = 0; i < list.getsize(); i++) {
        std::cout << list[i] <<std::endl; 
    }

    /* Delete the entire sheet and print its size */
    list.clear();
    std::cout << "Size: " << list.getsize() << std::endl;

    return 0;
}