#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"

class Queue : private MyList {
    public:
        int size();
        void pushFront(int data);
        void pushBack(int data);
        void push(int index, int data);
        void clean();
        void show();
        Queue(int value);
        Queue();
        ~Queue();
};

#endif