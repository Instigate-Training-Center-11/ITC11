#define STACK_H
#include "arrayStack.cpp"

template <class T> 
    class stack {
        private:
        T* data;
        int top;
        int size;
        void resize();
        bool needToResize();

        public:
        stack() {
            size = 5;
            data = new T[size];
            top = 0;
        }
        void push(T item);
        T peek();
        T pop();
        bool isEmpty();
    };

    
