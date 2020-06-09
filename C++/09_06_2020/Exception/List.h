#ifndef LIST_H
#define LIST_H

namespace Data {
/* This is header filedescribing user-defined type Linkedlist and Node. */
    template <typename T>
    class LinkedList {
        public:
            LinkedList();
            ~LinkedList();
            void showList();
            void removeElement(int number);
            T getElement(int number);
            void emptyList();
            void insertElement(T data, int number);

        private:
        class Node {
            public:
                T value;
                Node *address;
        };
        Node *firstElem;
        int length = 0;
    };
}

#endif