#ifndef _QUEUE_H
#define _QUEUE_H

#include "list.hpp"

template <typename Type>

class Queue : protected List<Type>
{
public:
    Queue();
    ~Queue();
};

#include "queue.tpp"

#endif