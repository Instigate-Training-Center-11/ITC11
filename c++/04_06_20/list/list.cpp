#include <iostream>
#include "list.h"

/* By user created Nde type description. */
/* Difoult constructor of List. */
List::List() {
    size = 0;
    first = nullptr;
}

/* This methog allows you to apply List elements with [] simbols. */
int& List::operator[](int index) {
    int count = 0;
    Node *current = this->first;
    while (current != nullptr) {
        if (count == index) {
            return current->data;
        }

        current = current->ptr;
        ++count;
    }
}

/* This method adds an element to the front of the list. */
void List::pushFront(int data) {
    first = new Node(data, first);
    ++List::size;
}

/* This method adds an element to the given index of the list. */
void List::insert(int data, int index) {
    if (index == 0) {
        pushFront(data);
    } else {
        Node *pre = first;
        for (int i = 0; i < index - 1; ++i) {
            pre = pre->ptr;
        }

        Node *insertNode = new Node(data, pre->ptr);
        pre->ptr = insertNode;
        ++List::size; 
    }
}

/* This method deletes an element to the given index of the list. */
void List::remove(int index) {
    if (index == 0) {
        popFront();
    } else {
        Node *post = first;
        for (int i = 0; i < index - 1; ++i) {
            post = post->ptr;
        }

        Node *newNode = post->ptr->ptr;
        post->ptr = newNode;
        --List::size;
    }
}

/* This method deletes an element to the front of the list. */
void List::popFront() {
    Node * temp = first;
    first = first->ptr;
    delete temp;
    --List::size;
}

/* This method deletes all List. */
void List::clear() {
    while (size) {
        popFront();
    }
    size = 0;
}

/* This method given size of the list. */
int List::getsize() {
    return size;
}

/* This method shows an all elements of the list. */
void List::show() {
    int i = 0;
    Node *temp = first;
    while (temp->ptr != nullptr)
    {
        std::cout << "[" << i << "]" << temp->data <<std::endl;
        ++i;
        temp = temp->ptr;
    }
    std::cout << "[" << i << "]" << temp->data <<std::endl;
}

/* This is destructor in List, that deleted all List ,when disappear object of List */
List::~List() {
    clear();
}