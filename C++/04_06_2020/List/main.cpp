#include <iostream>
#include "list.h"

int main() {
    /* Create the variable list with type LinkedList */
    List::LinkedList list;

    /* Insert elements. */
    list.insertElement(1);
    list.insertElement(5);
    list.insertElement(8);
    list.insertElement(4);

    /* Remove element by number of index from list. */
    list.removeElement(2);
    list.insertElement(88);

    /* Show aall list. */
    list.showElement();

    /* Show element by number of index from list. */    
    std::cout << "GET: " << list.getElement(0) << "\n";
    std::cout << "GET: " << list.getElement(2) << "\n";

    /* Empty all list */
    list.emptyList();

    return 0;
}