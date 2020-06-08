#include "queue.hpp"
#include <iostream>


void Queue::printQ(void) {
    printList();
}

void Queue::clearQ(void) {
    clear();
}

void Queue::pushBackQ(int value) {
    pushBack(value);
}

void Queue::popFrontQ(void) {
    popFront();
}

Queue::~Queue() {
    clear();
}