#include "node.h"

#ifndef LIST_H
#define LIST_H

    /*
    This is a list.h file that represents List the
    type that the user created.
    */
    class List {
        private:
            int size;
            Node *first;
        public:
            List();
            ~List();
            int& operator[](int index);
            void pushFront(int data);
            void insert(int data, int index);
            void popFront();
            void remove(int index);
            void clear();
            int getsize();
            void show();
            int getSize();
    };

#endif