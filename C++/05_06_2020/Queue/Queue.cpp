#include <iostream>
#include "Queue.h"

namespace Data {
    /* Constructor and Destructor for Queue. */
    Queue::Queue() {};
    Queue::~Queue() {
        std::cout << "Deleting from Queue destructor" << "\n";
        emptyList();
    };

    /* Delete the first element from Queue. */
    void Queue::deleteFirst() {
        int number = 0;
        removeElement(number);
    }

    /* Add element from end in Queue. */
    void Queue::addLast(int value) {
        insertElement(value, queueLen);
        ++queueLen;
    }

    /* Show all Queue. */
    void Queue::showQueue() {
        showList();
    }    
}