#include <iostream>
#include "List.h"

int main() {
    /* Create the variable list with type LinkedList */
    Data::LinkedList list;

    /* Insert elements by */
    list.insertElement(5, 0);
    list.insertElement(55, 0);
    list.insertElement(555, 0);
    list.insertElement(88, 2);

    /* Remove element by number of index from list. */
    list.removeElement(2);

    /* Show all list. */
    list.showList();

    /* Show element by number of index from list. */
    std::cout << "GET: " << list.getElement(2) << "\n";
    std::cout << "GET: " << list.getElement(0) << "\n";

    /* Empty all list */
    list.emptyList();

    /* Remove and insert elements. */
    std::cout << "Threads........" << "\n";
    list.insertThread(7777777, 0);
    list.removeThread(1);
    list.showList();

    return 0;
}