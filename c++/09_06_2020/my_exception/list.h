#include "node.h"

#ifndef LIST_H
#define LIST_H

    /* This is a list.h file that represents List the type that the user created. */
    template <typename T>
    class List {
        private:
            int size;
            Node<T> *first;
        public:
            List();
            ~List();
            T& operator[](int index);
            void pushFront(T data);
            void insert(T data, int index);
            void popFront();
            void remove(int index);
            void clear();
            int getsize();
            void show();
    };

#endif