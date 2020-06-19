#ifndef QUEUE_H
#define QUEUE_H

#include "list.hpp"

class Queue : private List
{
    public:
        Queue();
        void pushBack(int element);
        void pushFront(int element);
        void display();
        ~Queue();
};

#endif
