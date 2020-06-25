#include <iostream>
#include "stack.h"

/*constructor*/
template<typename T>
Stack<T>::Stack() {
    head = NULL;
    Size = 0;
}

/*copy construtor*/
template<typename T>
Stack<T>::Stack(const Stack& data) {
    Node<T> *current = data.head;
    Node<T> *tmp = new Node<T>(current->value);
    head = tmp;
    Node<T> *tail = tmp;
    while (current->next != NULL) {
        current = current->next;
        tmp = new Node<T>(current->value);
        tail->next = tmp;
        tail = tmp;
    }
}

/*destructor*/
template<typename T>
Stack<T>::~Stack() {
    if (NULL == head) {
        std::cout << "Nothing to clean" << std::endl;
    } else {
        std::cout << "Delete should be happening" << std::endl;
    }
}

/*pushed a node onto top of stack*/
template<typename T>
void Stack<T>::push(const T& val) {
    if (NULL == head) {
        head = new Node<T>(val);
    } else {
        Node<T>* current = this->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new Node<T>(val);
    }
    Size++;
}

/*pop top node off of the stack*/
template<typename T>
void Stack<T>::pop() {
    Node<T>* tmp = head;
    head = head->next;
    delete tmp;
    Size--;
}

/*Check the list is empty or not*/
template<typename T>
bool Stack<T>::isEmpty() {
    return NULL == head;
}

/*check the top element of stack*/
template<typename T>
T& Stack<T>::top() {
    std::cout << head->value << std::endl;
    return head->value;
}

/*Get the size of list*/
template<typename T>
size_type Stack<T>::size() const {
    return Size;
}

/*show the stack*/
template<typename T>
void Stack<T>::display() {
    if (head == NULL) {
        return;
    }
    Node<T> *current = head;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
