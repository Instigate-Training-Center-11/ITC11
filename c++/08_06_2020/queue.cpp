#include "queue.h"

/* Defoult constructor */
template <typename T>
Queue<T>::Queue() {};

/* This method deletes an element to the front of the Queue. */
template <typename T>
void Queue<T>::popFrontQueue() {
    this->popFront();
}

/* This method adds an element at last of the Queue. */
template <typename T>
void Queue<T>::pushBeackQueue(T data) {
    int length = this->getsize();
    this->insert(data, length);
}

/* This method shows an all elements of the Queue. */
template <typename T>
void Queue<T>::showQueue() {
    this->show();
}

/* This method deletes all Queue */
template <typename T>
void Queue<T>::clearQueue() {
    this->clear();
}

/*
This is destructor in Queue, that deleted all Queue,
when disappear object of Queue
*/
template <typename T>
Queue<T>::~Queue() {
    this->clearQueue();
}