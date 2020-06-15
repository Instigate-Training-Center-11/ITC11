#ifndef _LIST_H_
#define _LIST_H_

class List {
private:
    unsigned int size;
    struct Node {
        Node *next;
        int value;
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
    void insertAtIndex(unsigned int, int value);
    /* Set element by index */
    void setAtIndex(unsigned int, int value);
    /* Get element by index */
    int operator[](unsigned int) const;
    /* Print the whole list */
    void printList(void) const;
    /* Remove all elements from the list */
    void clear(void);
    /* Destructor  */
    ~List(void);
};

#endif