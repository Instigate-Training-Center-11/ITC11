#include "queue.hpp"

Queue::Queue() {
}

Queue::Queue(int value):List(value){
}

unsigned int Queue::size(void) {
    this->getSize();
}

void Queue::pop(void) {
    this->removeAtIndex(0);
}

void Queue::push(int value) {
    this->insertAtIndex(this->getSize(),value);
}

void Queue::show(void) {
    this->printList();
}

Queue::~Queue() {
}