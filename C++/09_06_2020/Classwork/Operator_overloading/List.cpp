#include <iostream>
#include "List.h"

namespace Data {
    /* Default constructor for LinkedList class. */
    LinkedList::LinkedList() {
        firstElem = 0;
        length = 0;
    }

    /* Destructor for LinkedList class. */
    LinkedList::~LinkedList() {
        std::cout << "Deleting from List destructor" << "\n";
        /* Delete all elements, while length of list is true. */
        while (length > 0) {
            Node *i = firstElem;
            firstElem = firstElem->address;
            delete i;
            --length;
        }
    }

    /* The written method adds an element to the list from the given position. */
    void LinkedList::insertElement(int value, int number) {
        /* Creates an item of the Node* type, that will be added to the list. */
        Node *temp1 = new Node();
        temp1->value = value;
        temp1->address = 0;
        if(number == 0) {
            temp1->address = firstElem;
            firstElem = temp1;
            return;
        }
        Node *temp2 = firstElem;
        /*
        Start at the first element and then we will go to the (number - 1) node
        with loop.
        */
        for (int i = 0; i < number - 1; ++i) {
            temp2 = temp2->address;
        }
        temp1->address = temp2->address;
        temp2->address = temp1;
        /* Increment the length of list after everi call this method. */
        ++length;
    }
    
    /* Display all list */
    void LinkedList::showList() {
        std::cout << "All elements is: " << "\n";
        Node *currElem = firstElem;
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
        /* Current element, which type of Node*, movinng the first index */
        Node *currElem = firstElem;
        /* If the entered number of index great, then current length of list, then do
        not continue executing. */
        if (number > length) {
            return;
        }
        if (number == 0) {
            firstElem = currElem->address;
            return;
        }
        for (int i = 0; i < number - 1; ++i) {
            currElem = currElem->address;
        }
        Node *addr = currElem->address->address;
        currElem->address = addr;
        /* Reducing the length of the list in everi deleting. */
        --length;
        delete currElem;
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
            Node *currElem = firstElem;
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
            stop the executing and print the text below.
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
            Node *i = firstElem;
            /* Go to the next element. */
            firstElem = firstElem->address;
            delete i;
            --length;
        }
    }

    std::ostream& LinkedList::show(std::ostream& stream) {
        Node *currElem = firstElem;
        do {
            stream << "Element is - " << currElem->value << "\n";            
            currElem = currElem->address;
        } while (currElem->address != 0);
        stream << "Element is - " << currElem->value << "\n";
        return stream;
    }

    /* Function, that implement operator overloading. */
    std::ostream& operator<<(std::ostream &out, LinkedList &list) {
        return list.show(out);
    }
}