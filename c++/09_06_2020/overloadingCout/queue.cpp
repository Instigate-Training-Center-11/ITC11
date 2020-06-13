#include "queue.hpp"

template <typename Type>
Queue<Type>::Queue() {
}

template <typename Type>
Queue<Type>::Queue(int value):List<Type>(value){
}

template <typename Type>
void Queue<Type>::size(void) {
    this->getSize();
}

template<typename T>
std::ostream& operator<< (std::ostream &out, const Queue<T> &obj) {
    obj.printList();
}

template <typename Type>
void Queue<Type>::pop(void) {
    this->removeAtIndex(0);
}

template <typename Type>
void Queue<Type>::push(Type value) {
    this->insertAtIndex(this->getSize(),value);
}

template <typename Type>
void Queue<Type>::show(void) {
    this->printList();
}

template <typename Type>
Queue<Type>::~Queue() {
}