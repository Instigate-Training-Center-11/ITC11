#include "list.h"

#ifndef QUEUE_H
#define QUEUE_H

    /*
    This is an queue.h file that represents Queue the type that
    the user created. Inheritance is performed with type private so
    that public methods are not inherited and do not spoil the
    behavior of Queue.
    */
    class Queue : private List {
        public:
            Queue();
            ~Queue();
            void popFrontQueue();
            void pushBeackQueue(int data);
            void showQueue();
            void clearQueue();
    };

#endif