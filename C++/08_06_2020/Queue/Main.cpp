#include <iostream>
#include "List.h"
#include "Queue.h"
#include "List.cpp"
#include "Queue.cpp"

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

    /* Show element by number of index from list. */
    std::cout << "GET: " << list.getElement(2) << "\n";
    std::cout << "GET: " << list.getElement(0) << "\n";

    /* Empty all list */
    list.emptyList();
    std::cout << "\n";

    std::cout << "From LinkedList, object 2: type = int" << "\n";
    /* Create the variable list2 with type LinkedList */
    Data::LinkedList<int> list2;

    /* Insert elements by */
    list2.insertElement(4, 0);
    list2.insertElement(9, 0);
    list2.insertElement(1, 0);

    /* Show all list. */
    list2.showList();
    std::cout << "\n";

    std::cout << "From Queue, object 1: type = double" << "\n";
    /* Create the variable queue with type Queue */
    Data::Queue<double> queue;

    /* Add element in queue in last index. */
    queue.addLast(11.9);
    queue.addLast(22.8);
    queue.addLast(33.1);
    queue.addLast(44.1);

    /* Delete first element from Queue. */
    queue.deleteFirst();

    /* Show all Queue. */
    queue.showQueue();
    std::cout << "\n";

    std::cout << "From Queue, object 2: type = std::string" << "\n";
    /* Create the variable queue2 with type Queue */
    Data::Queue<std::string> queue2;

    /* Add element in queue in last index. */
    queue2.addLast("a");
    queue2.addLast("b");
    queue2.addLast("c");

    /* Show all Queue. */
    queue2.showQueue();
    std::cout << "\n";

    return 0;
}