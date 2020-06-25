#ifndef STACK_H
#define STACK_H

typedef unsigned int size_type;

/*created new node*/
template<typename T>
class Node {
    public:
        T value;
        Node<T>* next;
        Node(T value, Node* next = NULL)
        {
            this->value = value;
            this->next = next;
        }
};

/*created class stack*/
template<typename T>
class Stack {
    public:
        /*constructor*/
        Stack();
        /*copy constructor*/
        Stack(const Stack<T>& data);
        /*pushed a node onto top of stack*/
        void push(const T& val);
        /*pop top node off of the stack*/
        void pop();
        /*get size of stack*/
        size_type size() const;
        /*check the top element of stack*/
        T& top();
        /*Check the list empty or not*/
        bool isEmpty();
        /*show the stack*/
        void display();
        /*destructor*/
        ~Stack();
    private:
        Node<T>* head;
        int Size;
};

#endif

