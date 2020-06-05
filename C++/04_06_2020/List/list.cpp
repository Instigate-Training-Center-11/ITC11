#include <iostream>
#include "list.h"

namespace List {
    /* Default constructor for LinkedList class. */
    LinkedList::LinkedList() {
        firstElem = 0;
        currElem = 0;
        i = 0;
    }

    /* Destructor for LinkedList class. */
    LinkedList::~LinkedList() {
        std::cout << "The List is empty from destructor" << "\n";
        /* Delete all elements, while length of list is true. */
        while (length > 0) {
            i = firstElem;
            firstElem = firstElem->address;
            delete i;
            --length;
        }
    }

    /* The written method adds an element to the list from the end. */
    void LinkedList::insertElement(int element) {
        /* Creates an item of the Node* type, that will be added to the list. */
        Node* newElement = new Node;
        newElement->address = 0;
        newElement->value = element;
        if (firstElem != 0) {
            currElem = firstElem;
            while(currElem->address != 0) {
                currElem = currElem->address;
            }
            currElem->address = newElement;
        } else {
            firstElem = newElement;
        }
        /* Increment the length of list after everi call this method. */
        ++length;
    }
    
    /* Display all list */
    void LinkedList::showElement() {
        std::cout << "The inserted list is: " << "\n";
        currElem = firstElem;
        /*
        As long as the current element in the list exist, go to the next item
        and print them all.
        */
        while (currElem != 0) {
            std::cout << currElem->value << "\n";
            currElem = currElem->address;
        }
    }

    /* This method delete the given element whit the position, that will given. */
    void LinkedList::removeElement(int number) {
        /* Reducing the length of the list in everi deleting. */
        --length;
        /* Current element, which type of Node*, movinng the first index */
        currElem = firstElem;
        if (number == 0) {
            firstElem = currElem->address;
            return;
        }
        for (int i = 0; i < number - 1; ++i) {
            currElem = currElem->address;
        }
        /* If the entered number of index great, then current length of list, then do
        not continue executing. */
        if (number > length) {
            return;
        }
        Node *addr = currElem->address->address;
        currElem->address = addr;
    }

    /* This method give the element by number of index. */
    int LinkedList::getElement(int number) {
        int count = 0;
        /*
        If the entered number of index is not equal the length of list, then
        continue executing.
        */
        if (number != length) {
            /* Current element, which type of Node*, movinng the first index */
            currElem = firstElem;
            while(currElem != 0) {
                if (count == number) {
                    return currElem->value;
                }
                ++count;
                currElem = currElem->address;
            }
        } else {
            /*
            If the entered number of index is not equal the length of list, then
            stop the executing and print the text below..
            */
            std::cout << "Element not exist!" << "\n";
            return 0;
        }
    }

    /* When will called this method, the list will be emptyed. */
    void LinkedList::emptyList() {
        std::cout << "The List is empty" << "\n";
        /* Delete all elements, while length of list is true. */
        while (length > 0) {
            i = firstElem;
            /* Go to the next element. */
            firstElem = firstElem->address;
            delete i;
            --length;
        }
    }
}