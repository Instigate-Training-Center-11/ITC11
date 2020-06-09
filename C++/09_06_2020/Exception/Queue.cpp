#include <iostream>
#include "Queue.h"

namespace Data {
    /* Constructor and Destructor for Queue. */
    template <typename T>
    Queue<T>::Queue() {};
    template <typename T>
    Queue<T>::~Queue() {
        std::cout << "Deleting from Queue destructor" << "\n";
        this->emptyList();
    };

    /* Delete the first element from Queue. */
    template <typename T>
    void Queue<T>::deleteFirst() {
        int number = 0;
        this->removeElement(number);
    }

    /* Add element from end in Queue. */
    template <typename T>
    void Queue<T>::addLast(T value) {
        this->insertElement(value, queueLen);
        ++queueLen;
    }

    /* Show all Queue. */
    template <typename T>
    void Queue<T>::showQueue() {
        this->showList();
    }    
}