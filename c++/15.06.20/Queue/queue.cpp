#include <iostream>
#include "queue.hpp"

/* Constructor and Destructor for Queue. */
Queue::Queue() {};
Queue::~Queue() {
    std::cout << "Deleting from Queue destructor" << "\n";
    clear();
};

/* Add element in Queue from back. */
void Queue::pushBack(int element) {
    push_back(element);
}

/* Add element in Queue from front. */
void Queue::pushFront(int element) {
    push_front(element);
}

/* Show all Queue. */
void Queue::display() {
    printf();
}

