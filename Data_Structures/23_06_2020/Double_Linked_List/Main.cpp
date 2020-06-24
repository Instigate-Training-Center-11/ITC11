#include <iostream>
#include "List.h"
#include "Iterator.h"
#include "List.cpp"

int main() {
    List<int> list = List<int>();

    /* Push elememts in end. */
    list.push_back(15);
    list.push_back(25);
    list.push_back(35);
    
    /* Push elememts in Front. */
    list.push_front(1);

    /* Insetr element by any posiition. */
    list.insert(2, 55555);

    /* First and last elements. */
    std::cout << "First and last elements: " << "\n";
    std::cout << list.front() << "\n";
    std::cout << list.back() << "\n";

    /* Delet element from end. */
    list.pop_back();

    /* Delet element from front. */    
    list.pop_front();

    /* List empty or not. */
    if(list.empty()) {
        std::cout << "List is empty" << "\n";
    } else {
        std::cout << "List is Not empty" << "\n";
    }

    /*
    Go through the Double linked list and print all the elements.
    */
    List<int>::iterator it1 = list.begin();
    std::cout << "All elements is: " << "\n";
    for (List<int>::iterator it = list.begin(); it != list.end(); it.operator++()) {
        std::cout << *it << "\n";
    }

    /* Double linked list size. */
    std::cout << "The size of all elements: " << "\n";
    std::cout << list.size() << "\n";

    return 0;
}