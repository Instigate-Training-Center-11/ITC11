#ifndef STACK_H
#define STACK_H

#include "vector.h"

    /**
    * @brief Implimentation stack
    * @version 1.0.0
    */
    template<typename T>
    class Stack : private Vector<T> {
        public:
            Stack();

            /**
             * @brief Insert the element in stack
             * @param value need get in function
             */
            void push(const T& value);

            /**
             * @brief Remove the element in binary tree
             */
            void pop();
            const T top();
            bool is_empty();
            int size();

        private:
            Vector<T> data;
    };
#endif