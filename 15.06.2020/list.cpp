#include <iostream>

#include "list.h"

/* Following is the constructor of MyList class */
MyList::MyList() {
    head = NULL;
    size = 0;
}

/* MyListSize is a member function of MyList class
which will return sizo of the creating List */
int MyListSize() {
    int size;
    return size;
}

/* PushFront is a member function of MyList class
which will push element given to it in front of the creating List */
void MyList::PushFront(int data) {
    head = new Node(data, head);
    size++;
}

/* PushBack is a member function of MyList class
which will push element given to it back to the creating List */
void MyList::PushBack(int data) {
    Node *temp = this->head;

    for (int i = 0; i != (size - 1); ++i) {
        temp = temp->next;
    }

    temp->next = new Node(data, temp->next);
    size++;
}

/* PrintList is a member function of MyList class
which print elements of the List */
void MyList::PrintList() {
    Node *temp = this->head;

    for(int i = 0; i < size; ++i) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

/* InsertElement is a member function of MyList class
which will insert the given element in the given index of List */
void MyList::InsertElement(int index, int data) {
    Node *temp = this->head;
    if(index != 0){
        for (int i = 0; i != (index - 1); ++i) {
            temp = temp->next;
        }
        temp->next = new Node(data, temp->next);
    } else {
        head = new Node (data, head);
    }

    size++;
}

/* GetElement is a member function of MyList class
which will get List element by index */
void MyList::GetElement(int index) {
    Node *temp = this->head;

    for (int i = 0; i != (index); ++i) {
        temp = temp->next;
    }

    std::cout << "List element by given index: " << temp->data << std::endl;
}

/* DestroyList is a member function of MyList class which will delete elements of List */
void MyList::DestroyList() {
    if(head != NULL) {
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

/* Following is the destructor of MyList class */
MyList::~MyList() {
    DestroyList();
}