#include <iostream>
#include "List.h"
#include "Queue.h"

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

    /* Create the variable queue with type Queue */
    Data::Queue queue;

    /* Add element in queue in last index. */
    queue.addLast(11);
    queue.addLast(22);
    queue.addLast(33);
    queue.addLast(44);

    /* Delete first element from Queue. */
    queue.deleteFirst();

    /* Show all Queue. */
    queue.showQueue();

    return 0;
}