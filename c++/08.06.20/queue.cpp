#include <iostream>
#include "list.hpp"
#include "queue.hpp"

template <typename T>
Queue<T>::Queue() {}

template <typename T>
void Queue<T>::insertItem(T element) {
    push_back();
}

template <typename T>
void Queue<T>::display() {
    this->printf();
}

template <typename T>
void Queue<T>::deleteItem() {
    this->pop_front();
}

template <typename T>
Queue<T>::~Queue() {}

