#include "List.h"

#ifndef QUEUE_H
#define QUEUE_H

namespace Data {
/*
This is header filedescribing user-defined type Queue. Inheritance of class
LinkedList performed with the type of protected, so the public methods of
LinkedList were not available for object with type Queue.
*/  
    template <typename T>
    class Queue : protected LinkedList<T> {
        public:
            Queue();
            ~Queue();
            void deleteFirst();
            void addLast(T value);
            void showQueue();
            int queueLen = 0;
    };     
}

#endif