#include <iostream>

/**
 * @brief Vector class
 * @version 1.0.0
 */

class Vector {
    public:
    /**
     * @brief Specify the minimum size of the vector
     * @param value - Value for function
     * @return Value, that will be returned (void)
     * @todo This function have status In Progress 60%
     * @throw memory error in case of insufficient memory
     */
    void reserve(int);
    /**
     * @brief Reduces memory usage by freeing unused memory
     * @return Value, that will be returned (void)
     * @todo This function have status In Progress 50%
     * @warning Dont use this function whit any argument
     * @deprecated This function already deprecated
     * @throw memory error in case of insufficient memory
     */
    void shrink_to_fit();
    /**
     * @brief Resizes the container
     * @return Value, that will be returned (void)
     * @todo This function have status In Progress 60%
     * @throw memory error in case of insufficient memory
     * @private This method will become private
     */
    void resize();
    /**
     * @brief ENUM
     */
    enum type {
        a, ///< parametr a
        b, ///< parametr b
        c, ///< parametr c
    };
};