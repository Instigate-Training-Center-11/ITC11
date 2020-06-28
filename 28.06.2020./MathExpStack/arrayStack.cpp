#ifndef STACK_H
#include "arrayStack.h"
#endif

template <class T>
void stack<T>::push (T item) {
    if (needToResize()){   
        resize();
        data[top] = item;
    }
        top++;
    }

    template <class T>
    T stack<T>::peek() 
        if (top <= 0) {
            std::cout << "Attempted to peek an empty stack." << std::endl;        
            return data[top-1];
    }
template <class T>
T stack<T>::pop() {
    if (top <= 0){
        std::cout << "Attempted to peek an empty stack." << std::endl;
    }    
            top--;
            return data[top];    
}
template <class T>
bool stack<T>::needToResize() {
    return (top == size);
}
template <class T>
void stack<T>::resize () {
    T* newdata = new T [2*size];
    for (int i = 0; i <size; i++) {
        newdata[i] = data[i];
        data = newdata;
        size *= 2;
    }
}
template <class T>
bool stack<T>::isEmpty() {
    return (top == 0);
}

 // ~arrayStack();
