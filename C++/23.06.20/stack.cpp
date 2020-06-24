#include "stack.hpp"

template<typename Type, class Container>
    Stack<Type, Container>::Stack() {
        this->stack_size = 0;
    }

template<typename Type, class Container>
    Stack<Type, Container>::Stack(int size, Type value) {
        this->stack_size = size;
        for (int i = 0; i < size; ++i) {
            this->stack.push_back(value);
        }
    }

template<typename Type, class Container>
    void Stack<Type, Container>::pop() {
        this->stack.pop_back();
        --stack_size;
    }

template<typename Type, class Container>
    void Stack<Type, Container>::push(Type value) {
        this->stack.push_back(value);
        ++stack_size;
    }

template<typename Type, class Container>
    int Stack<Type, Container>::size() {
        return this->stack_size;
    }

template<typename Type, class Container>
    bool Stack<Type, Container>::empty() {
        if (stack_size == 0) {
            return true;
        } else {
            return false;
        }
    }

template<typename Type, class Container>
    auto& Stack<Type, Container>::top() {
        return stack.back();
    }