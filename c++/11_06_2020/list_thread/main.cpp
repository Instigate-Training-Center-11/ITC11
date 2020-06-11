#include <iostream>
#include "list.h"

int main() {
    /* Adding and remove elements in the list using threads. */
    List list;

    list.insertThread(25, 0);
    list.insertThread(5, 1);
    list.show();
    std::cout << std::endl;

    list.removeTread(0);
    list.show();
    return 0;
}