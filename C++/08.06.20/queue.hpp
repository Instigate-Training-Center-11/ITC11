#include "list.hpp"
#ifndef _QUEUE_HPP
#define _QUEUE_HPP



template<typename Type>
class Queue : protected List<Type> {
    public:
        Queue();
        void push_back_queue(Type);
        void pop_front_queue();
        void print_queue();
        ~Queue();
};

#include "queue.tpp"
#endif