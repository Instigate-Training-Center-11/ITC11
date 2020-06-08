#include <iostream>
#include "queue.hpp"

template<typename Type>
Queue<Type>::Queue() {

}

template<typename Type>
void Queue<Type>::push_back_queue(Type value) {
    this->push_back(value);
}

template<typename Type>
void Queue<Type>::pop_front_queue() {
    this->pop_front();
}

template<typename Type>
void Queue<Type>::print_queue() {
    this->print();
}

template<typename Type>
Queue<Type>::~Queue() {
    this->clear();
}