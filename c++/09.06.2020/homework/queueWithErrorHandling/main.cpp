#include <iostream>

#include "list.hpp"
#include "myException.hpp"

#include "list.cpp"
#include "node.cpp"
#include "queue.cpp"

/* Functions prototypes */
template<typename T>
int getNumber(std::string key, int number = 0);

int main() {
    /* Get size of list */
    int size = 0;
    while (size < 1) {
        size = getNumber<int>("Enter link size(> 1): ");
    }

    /* Create list by size and initialize it */
    List<int>* list = new List<int>();
    for (int i = 0; i < size; ++i) {
        int value = getNumber<int>("Enter element ", i + 1);
        list->insertElement(i, value);
    }

    /* Print created list pretty */
    std::cout << "******* List *******" << std::endl;
    list->show();
    std::cout << "*** Now length is: " << list->getLength() << std::endl;

    /* Try to add element by index or print exception message */
    int index = -1;
    while (index < 1) {
        index = getNumber<int>("Enter index to add element(> 0): ");
    }
    int value = getNumber<int>("Enter value of element: ");
    try {
        list->insertElement(index, value);
        std::cout << "New node added!" << std::endl;
    } catch (MyException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "******* List *******" << std::endl;
    list->show();
    std::cout << "*** Now length is: " << list->getLength() << std::endl;

    /* try to delete element by index or print exception message */
    index = -1;
    while (index < 0) {
        index = getNumber<int>("Enter index to delete element(> 0): ");
    }

    try {
        list->removeElement(index);
        std::cout << "New node added!" << std::endl;
    } catch (MyException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "******* List *******" << std::endl;
    list->show();
    std::cout << "*** Now length is: " << list->getLength() << std::endl;

    /* Try to get element by index or print exception message */
    index = -1;
    while (index < 1) {
        index = getNumber<int>("Enter index to get element(> 0): ");
    }

    try {
        std::cout << "Element is: " << list->getElement(index) << std::endl;
    } catch (MyException& e) {
        std::cout << e.what() << std::endl;
    }

    /* Clear the list all elements */
    std::cout << "******* Now clear the list *******" << std::endl;
    list->empty();
    std::cout << "Is empty the list? ";
    if (list->isEmpty()) {
        std::cout << "Yes, list is empty!" << std::endl;
    } else {
        std::cout << "List isn't empty!" << std::endl;
    }

    /* Delete used memory */
    delete list;
    return 0;
}

/* Function return number
    args:
     key : what we want
     number: index number
*/
template<typename T>
int getNumber(std::string key, int number) {
    T n = 0;
    if (0 == number) {
        std::cout << key;
    } else {
        std::cout << key << number << ": ";
    }
    std::cin >> n;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout << "Warning: Enter only number!!!" << std::endl;
        if (0 == number) {
            std::cout << key;
        } else {
            std::cout << key << number << ": ";
        }
        std::cin >> n;
    }

    return n;
}