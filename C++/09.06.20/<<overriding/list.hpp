#include "node.hpp"
#ifndef _LIST_HPP
#define _LIST_HPP

/* Error codes */
/* 101 out of list, not find index */
const int ERROR_101 = 101;
/* 202 empty list */
const int ERROR_202 = 202;

template<typename Type>
class List {
    int size;
    Node<Type>* head;
    Node<Type>* tail;

    public:

    /* Default constructor */
    List();

    /* Constructor with arguments(overload) */
    List(int size,Type value = Type());

    /* Constructor copy other list(overload) */
    List(List& copy);

    /* Destructor */
    ~List();

    /* This method return size of list */
    int get_size() const;

    /* This method delete all values from list */
    void clear();

    List<Type> operator+(const List<Type>& lst1);

    void operator=(const List<Type>& lst1);

    const bool operator==(const List<Type>& right);

    const bool operator!=(const List<Type>& right);

    Type& operator[](const int index);

    /* This function add new value in back of list */
    void push_back(Type value);

    /* This method add new value in front of list */
    void push_front(Type value);

    /* This method remove value from back of list */
    void pop_back();

    /* This method remove value from front of list */
    void pop_front();

    /* This method print all values in list */
    void print() const;

    template<typename T>
    friend std::ostream& operator<<(std::ostream& out, List<T>& list);
};

#endif