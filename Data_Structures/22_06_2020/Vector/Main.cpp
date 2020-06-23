#include <iostream>
#include "Vector.h"
#include "Iterator.h"
#include "Vector.cpp"

int main() {
    Vector<int> vec;

    /* Insert elements in end */
    std::cout << "Length after insert: " << "\n";
    vec.push_back(5);
    vec.push_back(15);
    vec.push_back(25);

    /* Before shrink_to_fit() */
    std::cout << vec.size() << "\n";
    std::cout << vec.capacity() << "\n";

    /* After shrink_to_fit() */
    std::cout << "shrink_to_fit(): " << "\n";
    vec.shrink_to_fit();
    std::cout << vec.size() << "\n";
    std::cout << vec.capacity() << "\n";

    /* Delete element from end */
    std::cout << "Length after pop_back(): " << "\n";
    vec.pop_back();
    std::cout << vec.size() << "\n";

    /* Empty or not */
    if (vec.empty()) {
        std::cout << "The vector is empty" << "\n";
    } else {
        std::cout << "Not empty" << "\n";
    }

    /* Change the size */
    std::cout << "Change the size of vector: " << "\n";
    vec.resize(14);
    std::cout << vec.size() << "\n";

    /* Request a change in capacity  */
    std::cout << "Request a change in capacity: " << "\n";
    vec.reserve(88);
    std::cout << vec.capacity() << "\n";

    /*
    Go through the vector and print all the elements
    */
    std::cout << "All elements is: " << "\n";
    for (Vector<int>::iterator it = vec.begin(); it != vec.end(); it.operator++()) {
        std::cout << *it << "\n";
    }

    /* Take element the vector with [] */
    std::cout << "Use the []: " << "\n";
    std::cout << vec[1] << "\n";

    /*
    To check the operation of operator==(); operator--(). The others overloaded
    operators works in a similar way.
    */
    Vector<int>::iterator it1 = vec.begin();
    Vector<int>::iterator it2 = vec.begin();

    if (it1.operator==(it2)) {
        std::cout << "Equal" << "\n";
    } else {
        std::cout << "Not equal" << "\n";
    }

    it1.operator--();
    if (it1.operator==(it2)) {
        std::cout << "Equal" << "\n";
    } else {
        std::cout << "Not equal" << "\n";
    }
  
    return 0;
}