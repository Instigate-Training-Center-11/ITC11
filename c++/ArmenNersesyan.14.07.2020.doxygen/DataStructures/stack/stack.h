#ifndef _STACK_H_
#define _STACK_H_

#include "vector.h"

template<typename Type, class Adaptr = MyVector<Type>>

class Stack {
private:
    int stackSize;
    Adaptr stack;
public:

    Stack();
    Stack(int size, Type value);
    void pop();
    void push(Type value);
    int size();
    bool empty();
    Type top();

};

#include "stack.cpp"
#endif