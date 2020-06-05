#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"

class List {
    private:
        Node* node;
        int length;
        Node* head;
    public:
        int getLength();
        int getElement(int);
        bool insertElement(int, int);
        void insertFirst(int);
        void insertLast(int);
        bool removeElement(int);
        void removeFirst();
        void removeLast();
        bool empty();
        void show();
        bool isEmpty();
        List();
        List(int);
        ~List();
};

#endif