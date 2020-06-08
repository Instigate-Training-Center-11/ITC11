#ifndef QUEUE_H
#define QUEUE_H

#include "list.hpp"

class Queue : protected List {
    public:
    /* Remove the last item from the Q */
    void popFrontQ(void);
    /* Push the new item at the end of the Q */
    void pushBackQ(int);
    /* Print the whole list */
    void printQ(void);
    /* Remove all elements from the Q */
    void clearQ();
    ~Queue();
};

#endif