#ifndef DATA_HPP
#define DATA_HPP

class Data {
public:
    Data();
    ~Data();

    /* This method return size of list */
    virtual int get_size() const = 0;

    /* This method delete all values from list */
    virtual void clear() = 0;

    /* This method return value by index */
    virtual int get_at_index(int) const = 0;

    /* This method change value by index */
    virtual void set_at_index(int, int) = 0;

    /* This method remove value by index */
    virtual void remove_at_index(int) = 0;

    /* This function add new value in back of list */
    virtual void push_back(int) = 0;

    /* This method add new value in front of list */
    virtual void push_front(int) = 0;

    /* This method remove value from back of list */
    virtual void pop_back() = 0;

    /* This method remove value from front of list */
    virtual void pop_front() = 0;

    /* This method return maximum value of list */
    virtual int get_max() const = 0;

    /* This method return minimum value of list */
    virtual int get_min() const = 0;

    /* This method print all values in list */
    virtual void print() const = 0;
};

#endif