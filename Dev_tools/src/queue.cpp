#include <iostream>
#include "queue.hpp"

Queue::Queue() {

}

void Queue::push_back_queue(int value) {
    push_back(value);
}

void Queue::pop_front_queue() {
    pop_front();
}

void Queue::print_queue() {
    print();
}

Queue::~Queue() {

}