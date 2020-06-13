#ifndef _LIST_H_
#define _LIST_H_
#include <fstream>

template <typename Type>

class List {
private:
    struct Node {
        Node *next;
        Type value;
    };
    Node *head;
    unsigned int size;

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
    virtual Type operator[](unsigned int) const;
    /* Print the whole list */
    void printList(void) const;
    /* Remove all elements from the list */
    void clear(void);
    /* Destructor  */
    template<typename T>
    friend std::ostream& operator<< (std::ostream &out, const List<T> &obj);
    ~List(void);
};

#include "list.cpp"
#endif