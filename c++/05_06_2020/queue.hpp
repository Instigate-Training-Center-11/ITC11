#ifndef QUEUE_H
#define QUEUE_H

#include "list.hpp"

class Queue : protected List {
    public:
    Queue();
    void popFrontQ(void);
    void pushBackQ(int);
    void printQ(void);
    void clearQ();
    ~Queue();
};

#endif