#include "node.hpp"

#ifndef LIST_HPP
#define LIST_HPP

/* Error codes */
/* 101 out of list, not find index */
const int ERROR_101 = 101;
/* 202 empty list */
const int ERROR_202 = 202;

class List {
    class Node {
        public:
        Node* next;
        int value;

        /* Constructor with default arguments for class Node */
        Node(int value = 0, Node* node = nullptr) : value(value), next(node) {

        }
    };

    int size;
    Node* head;
    Node* tail;

    public:

    /* Default constructor */
    List();

    /* Constructor with arguments(overload) */
    List(int size, int value = 0);

    /* Destructor */
    ~List();

    /* This method return size of list */
    int get_size() const;

    /* This method delete all values from list */
    void clear();

    /* This method return value by index */
    int get_at_index(int) const;

    /* This method change value by index */
    void set_at_index(int, int);

    /* This method remove value by index */
    void remove_at_index(int);

    /* This function add new value in back of list */
    void push_back(int);

    /* This method add new value in front of list */
    void push_front(int);

    /* This method remove value from back of list */
    void pop_back();

    /* This method remove value from front of list */
    void pop_front();

    /* This method return maximum value of list */
    int get_max() const;

    /* This method return minimum value of list */
    int get_min() const;

    /* This method print all values in list */
    void print() const;
};

#endif