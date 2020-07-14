#ifndef QUEUE_HPP

#include "list.hpp"

class Queue : protected List {
    public:
        /**
         * @brief Default constructor
         */
        Queue();

        /**
         * @brief Adds a new element at the end of the queue
         * @param value - value
         */
        void push_back_queue(int value);

        /**
         * @brief Remove element at the front of the list
         */
        void pop_front_queue();

        /**
         * @brief Print all values in list
         */
        void print_queue();

        /**
         * @brief Destructor
         */
        ~Queue();
};

#endif