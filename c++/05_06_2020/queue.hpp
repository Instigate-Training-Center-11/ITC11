#ifndef _QUEUE_H
#define _QUEUE_H

#include "list.hpp"

class Queue : protected List {
public:
    Queue();
    Queue(int);
    void show(void);
    unsigned int size(void);
    void pop(void);
    void push(int value);
    ~Queue();
};

#endif