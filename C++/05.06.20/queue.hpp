#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "list.hpp"

class Queue : protected List {
    public:
        Queue();
        void push_back_queue(int value);
        void pop_front_queue();
        void print_queue();
        ~Queue();
};

#endif