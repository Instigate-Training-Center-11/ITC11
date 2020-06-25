#include "stack.h"

template<typename Type, class Adaptr>
Stack<Type, Adaptr>::Stack() {
    this->stackSize = 0;
}

template<typename Type, class Adaptr>
Stack<Type, Adaptr>::Stack(int size, Type value) {
    this->stackSize = size;
    for (int i = 0; i < size; ++i) {
        this->stack.pushBack(value);
    }
}

template<typename Type, class Adaptr>
void Stack<Type, Adaptr>::pop() {
    this->stack.popBack();
    --stackSize;
}

template<typename Type, class Adaptr>
void Stack<Type, Adaptr>::push(Type value) {
    this->stack.pushBack(value);
    ++stackSize;
}

template<typename Type, class Adaptr>
int Stack<Type, Adaptr>::size() {
    return this->stackSize;
}

template<typename Type, class Adaptr>
bool Stack<Type, Adaptr>::empty() {
    return stack.empty();
}

template<typename Type, class Adaptr>
Type Stack<Type, Adaptr>::top() {
    return stack.back();
}