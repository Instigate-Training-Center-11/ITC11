#include <iostream>

#include "queue.h"

int Queue::size() {
    MyListSize();
}

void Queue::pushFront(int data) {
    PushFront(data);
}

void Queue::pushBack(int data) {
    PushFront(data);
}

void Queue::push(int index, int data) {
    InsertElement(index, data);
}

void Queue::clean() {
    return DestroyList();
}

void Queue::show() {
    PrintList();
}

Queue::Queue() {

}

Queue::~Queue() {
    DestroyList();
}