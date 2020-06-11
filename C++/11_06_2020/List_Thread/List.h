#ifndef LIST_H
#define LIST_H

namespace Data {
/* This is header filedescribing user-defined type Linkedlist and Node. */
    class LinkedList {
        public:
            LinkedList();
            ~LinkedList();
            void showList();
            void removeElement(int number);
            int getElement(int number);
            void emptyList();
            void insertElement(int value, int number);
            void insertThread(int value, int number);
            void removeThread(int number);

        private:
        class Node {
            public:
                int value;
                Node *address;
        };
        Node *firstElem;
        int length;
    };
}

#endif