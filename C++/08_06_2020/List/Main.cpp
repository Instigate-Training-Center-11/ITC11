#include <iostream>
#include "List.h"
#include "List.cpp"

int main() {
    std::cout << "From LinkedList, object 1: type = std::string" << "\n";
    /* Create the variable list with type LinkedList */
    Data::LinkedList<std::string> list;

    /* Insert elements by */
    list.insertElement("a", 0);
    list.insertElement("aa", 0);
    list.insertElement("aaa", 0);
    list.insertElement("aaaa", 2);

    /* Remove element by number of index from list. */
    list.removeElement(2);

    /* Show all list. */
    list.showList();
    std::cout << "\n";

    /* Show element by number of index from list. */
    std::cout << "GET: " << list.getElement(2) << "\n";
    std::cout << "GET: " << list.getElement(0) << "\n";

    /* Empty all list */
    list.emptyList();

    std::cout << "From LinkedList, object 2: type = double" << "\n";
    /* Create the variable list2 with type LinkedList */
    Data::LinkedList<double> list2;

    /* Insert elements by */
    list2.insertElement(4.7, 0);
    list2.insertElement(9.6, 0);
    list2.insertElement(1.2, 0);

    /* Show all list. */
    list2.showList();

    /* Empty all list */
    list2.emptyList();
    std::cout << "\n";

    return 0;
}