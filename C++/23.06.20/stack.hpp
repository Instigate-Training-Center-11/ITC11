#ifndef STACK_HPP
#define STACK_HPP

#include <vector>
#include <deque>
#include <list>

template<typename Type, class Container = std::deque<Type>>

class Stack {
private:
    int stack_size;
    Container stack;
public:
    Stack();

    Stack(int size, Type value);

    void pop();

    void push(Type value);

    int size();

    bool empty();

    auto& top();
};

#endif