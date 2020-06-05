#ifndef LIST_H
#define LIST_H

namespace List {
/* This is header filedescribing user-defined type Linkedlist and Node. */
    class LinkedList {
        public:
            LinkedList();
            ~LinkedList();
            void insertElement(int element);
            void showElement();
            void removeElement(int number);
            int getElement(int number);
            void emptyList();

        private:
        class Node {
            public:
                int value;
                Node* address;
        };
        Node *firstElem;
        Node *currElem;
        Node *i;
        int length = 0;       
    };     
}

#endif