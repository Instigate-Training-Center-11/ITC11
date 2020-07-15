#ifndef _VECTOR_H_
#define _VECTOR_H_
#include<iostream>
template <typename Type>

class MyVector {
    Type* arr;
    unsigned int size;
    unsigned int reserveSize;
    public:
	/** @brief empty container constructor (default constructor) Constructs an empty container, with no elements. 
	 */
    MyVector(void);
	/** @brief Constructs a container with n elements. Each element is a copy of value. 
	 */
    MyVector(unsigned int constructorSize, Type value);
  	/** @brief Destroys the container object. 
	 */
    ~MyVector(void);
	/** @brief Requests the container to reduce its capacity to fit its size.
	 */
    void shrinkToFit(void);
	/** @brief Requests that the vector capacity be at least enough to contain res elements.
	 *  @param unsigned int - res
	 */
    void reserve (unsigned int res);
	/** @brief Returns whether the vector is empty (i.e. whether its size is 0). 
	 *  @return bool - true if the container size is 0, false otherwise.
	 */
    bool empty(void) const;
	/** @brief Return size of allocated storage capacity 
	 *  @return unsigned int - size Capacity
	 */
    unsigned int sizeCapacity(void)const;
	/** @brief Returns the number of elements in the vector.
	 *  @return unsigned int - size vector
	 */
    unsigned int getSize(void) const;
	/** @brief Adds a new element at the end of the vector, after its current last element. 
	 *  The content of val is copied (or moved) to the new element.
	 *  @param const Type& - value
	 */
    void PushBack(const Type& newelement);
	/** @brief Removes the last element in the vector, effectively reducing the container size by one.
	 */
    void popBack(void);
	/** @brief removes an item from the front, effectively reducing the container size by one.
	 */
    void popFront(void);
	/** @brief Print the current vector 
	 */
    void print(void) const;
    Type* begin(void);
    Type back(void);

};

#include "vector.cpp"
#endif
