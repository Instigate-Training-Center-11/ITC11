#include <iostream>
#include "list.h"
#include <thread>

/*
By user created Nde type description.
Difoult constructor of List.
*/
List::List() {
    size = 0;
    first = nullptr;
}

/* This methog allows you to apply List elements with [] simbols. */
int& List::operator[](int index) {
    if (index >= size) {
        std::cout << "There is no element in the List with [";
        std::cout << index << "] index." << std::endl;
    } else {
        int count = 0;
        Node *current = this->first;
        while (nullptr != current) {
            if (count == index) {
                return current->data;
            }

            current = current->ptr;
            ++count;
        }
    }
}

/* This method adds an element to the front of the list. */
void List::pushFront(int data) {
    first = new Node(data, first);
    ++List::size;
}

/* This method adds an element to the given index of the list. */
void List::insert(int data, int index) {
    if (0 == index) {
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
    if (0 != size) {
        if (0 == index) {
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
    } else {
        std::cout << "This List is empty!!!" << std::endl;
    }
}

/* This method deletes an element to the front of the list. */
void List::popFront() {
    Node *temp = first;
    first = first->ptr;
    delete temp;
    --List::size;
}

/* This method deletes all List. */
void List::clear() {
    while (size) {
        popFront();
    }
}

/* This method given size of the list. */
int List::getsize() {
    return size;
}

/* This method shows an all elements of the list. */
void List::show() {
    int i = 0;
    Node *temp = first;
    while (nullptr != temp->ptr) {
        std::cout << "[" << i << "]" << temp->data << std::endl;
        ++i;
        temp = temp->ptr;
    }
    std::cout << "[" << i << "]" << temp->data << std::endl;
}

/* This method adds an element with another thread to the given index of the list. */
void List::insertThread(int data, int index) {
    std::thread th1(&List::insert, this, data, index);
    if(th1.joinable()) {
        th1.join();
    }
}

/* This method deletes an element to the given index of the list with another thread. */
void List::removeTread(int index) {
    std::thread th2(&List::remove, this, index);
    if(th2.joinable()) {
        th2.join();
    }
}

/* This is destructor in List, that deleted all List ,when disappear object of List */
List::~List() {
    clear();
}