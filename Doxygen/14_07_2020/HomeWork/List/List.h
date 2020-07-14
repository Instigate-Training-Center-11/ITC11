#include <iostream>

/**
 * @brief List class
 * @version 1.0.0
 */

class List {
    public:
    /**
     * @brief Add element in the end of List
     * @param value - Value for node
     * @return Value, that will be returned (void)
     * @todo This function have status In Progress 20%
     * @warning Dont use this function whitout argument
     * @deprecated This function will deprecated from 1 year
     * @throw memory error in case of insufficient memory
     */
    void pushBack(int);
    /**
     * @brief Delete element from end of List
     * @param value - Value for node
     * @return Value, that will be returned (void)
     * @todo This function have status In Progress 80%
     * @throw memory error in case of insufficient memory
     * 
     * @code
     *  void List::popBack(int value) {
            std::cout << "This function will delete element from end of list" << "\n"; 
        }
     * @endcode
     */
    void popBack(int);
};