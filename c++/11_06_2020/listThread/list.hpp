#ifndef _LIST_H_
#define _LIST_H_

#include "exception.hpp"

template <typename Type>

class List {
private:
    unsigned int size;
    struct Node
    {
        Node *next;
        Type value;
    };
    Node *head;

public:
    /* default constructor */
    List(void);
    /* Parameterized constructor */
    List(int);
    unsigned int getSize(void) const;
    /* Remove element by index */
    void removeAtIndex(unsigned int);
    /* Insert element by index */
    void insertAtIndex(unsigned int, Type);
    /* Set element by index */
    void setAtIndex(unsigned int, Type);
    /* Get element by index */
    void deleteThread(unsigned int);
    void insertAtIndexThread(unsigned int, int);
    Type operator[](unsigned int) const;
    /* Print the whole list */
    void printList(void) const;
    /* Remove all elements from the list */
    void clear(void);
    /* Destructor  */
    ~List(void);
};

#include "list.cpp"
#endif