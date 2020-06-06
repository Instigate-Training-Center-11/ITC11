#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "data.hpp"

class Vector : public Data {
    int* array;
    int size;
    int capacity;

    public:
    Vector();

    Vector(int size);

    Vector(int size, int value);

    ~Vector();

    /* This method return size of vector */
    int get_size() const;

    /* This method delete all values from vector */
    void clear();

    /* This method return value by index */
    int get_at_index(int) const;

    /* This method change value by index */
    void set_at_index(int, int);

    /* This method remove value by index */
    void remove_at_index(int);

    /* This function add new value in back of vector */
    void push_back(int);

    /* This method add new value in front of vector */
    void push_front(int);

    /* This method remove value from back of vector */
    void pop_back();

    /* This method remove value from front of vector */
    void pop_front();

    /* This method return maximum value of vector */
    int get_max() const;

    /* This method return minimum value of vector */
    int get_min() const;

    /* This method print all values in vector */
    void print() const;

    /* This method doing smaller capacity */
    void shrink_to_fit();

    /* This swap method */
    void swap(int, int);

    /* This swap method(overload) */
    void swap(Vector &vector, int, int);

    /* This swap method(overload) */
    void swap(Vector &vector);

    /* Sorting vector */
    void sort(int) const;

    /* Insertation by index */
    void insert_at_index(int, int);

    /* This method return capacity */
	int get_capacity() const;
};

#endif