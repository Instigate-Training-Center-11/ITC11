#include "list.hpp"
#ifndef _QUEUE_HPP
#define _QUEUE_HPP



template<typename Type>
class Queue : public List<Type> {
    public:
        Queue();
        Queue(int, Type);
        void push_back_queue(Type);
        void pop_front_queue();
        void print_queue();
        ~Queue();
};

#include "queue.tpp"
#endif