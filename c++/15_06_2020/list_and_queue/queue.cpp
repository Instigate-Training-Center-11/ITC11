#include "queue.h"

/* Defoult constructor */
Queue::Queue() {};

/* This method deletes an element to the front of the Queue. */
void Queue::popFrontQueue() {
    popFront();
}

/* This method adds an element at last of the Queue. */
void Queue::pushBeackQueue(int data) {
    int length = getsize();
    insert(data, length);
}

/* This method shows an all elements of the Queue. */
void Queue::showQueue() {
    show();
}

/* This method deletes all Queue */
void Queue::clearQueue() {
    clear();
}

/*
This is destructor in Queue, that deleted all Queue,
when disappear object of Queue
*/
Queue::~Queue() {
    clearQueue();
}