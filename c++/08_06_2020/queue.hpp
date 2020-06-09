#ifndef _QUEUE_H
#define _QUEUE_H

#include "list.hpp"

template <typename Type>

class Queue : protected List<Type> {
public:
    Queue();
    Queue(int);
    void show(void);
    void size(void);
    void pop(void);
    void push(Type);
    ~Queue();
};

#include "queue.cpp"

#endif