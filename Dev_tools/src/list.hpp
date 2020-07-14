#ifndef LIST_HPP
#include "node.hpp"

// Error codes
const int ERROR_101 = 101; // out of list, not find index
const int ERROR_202 = 202; // empty list

/**
 * \brief Data structure List
 * \author Artashes Sargsyan
 * \version 1.0
 * \date 2020 june
 * \warning This class is created for training purposes.
 */

class List {
    /**
     *  \brief Class Node
     */

    int size;
    Node* head;
    Node* tail;

    public:

    /**
     * @brief Default constructor
     */
    List();

    /**
     * Constructor with arguments(overload)
     * @brief Create object
     * @param size - size for new list
     * @param value - value for all members in list(by default value = 0)
     */
    List(int size, int value = 0);

    /**
     * Destructor
     * @brief Delete object
     */
    ~List();

    /**
     *  @brief This method return size of list
     */
    int get_size() const;

    /**
     * @brief Clear all nodes
     */
    void clear();

    /**
     * @brief Return value by index
     * @param index - index
     * @return current value by index
     */
    int get_at_index(int index) const;

    /**
     * @brief Change value by index
     * @param value - value
     * @param index - index
     */
    void set_at_index(int value, int index);

    /**
     * @brief Remove element by index
     * @param index - index
     */
    void remove_at_index(int index);

    /**
     * @brief Adds a new element at the end of the list
     * @param value - value
     */
    void push_back(int value);

    /**
     * @brief Adds a new element at the front of the list
     * @param value - value
     */
    void push_front(int value);

    /**
     * @brief Remove element at the back of the list
     */
    void pop_back();

    /**
     * @brief Remove element at the front of the list
     */
    void pop_front();

    /**
     * @brief Find maximum in list
     * @return maximum value in list
     */
    int list_max() const;

    /**
     * @brief Find minimum in list
     * @return minimum value in list
     */
    int list_min() const;

    /**
     * @brief Reverse for list
     */
    void reverse();

    /**
     * @brief Print all values in list
     */
    void print() const;
};

#endif