#ifndef LIST_H
#define LIST_H


/* MyList and Node are public classes*/
class MyList {
    public:
        MyList();
        int size;
        int MyListSize();
        void PushFront(int data);
        void PushBack(int data);
        void InsertElement(int index, int data);
        void GetElement(int index);
        void PrintList();
        void DestroyList();
        ~MyList();

        class Node {
            public:
                int data;
                Node* next;
                Node(int data, Node *next = NULL) {
                    this->data = data;
                    this->next = next;
                }
        };

    Node *head;
};

#endif