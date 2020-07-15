#ifndef _STACK_H_
#define _STACK_H_

#include "vector.h"

template<typename Type, class Adaptr = MyVector<Type>>

class Stack {
private:
    int stackSize;
    Adaptr stack;
public:
    /** @brief default constructor stack 
	 */
    Stack();
	/** @brief stack parameter constructor 
	 */
    Stack(int size, Type value);
	/** @brief Removes the element on top of the stack, effectively reducing its size by one. 
	 */
    void pop();
	/** @brief Inserts a new element at the top of the stack, above its current top element. 
	 * 	The content of this new element is initialized to a copy of val. 
	 */
    void push(Type value);
	/** @brief Returns the number of elements in the stack.
	 *  @return unsigned int - size
	 */
    unsigned int size();
	/** @brief Returns whether the stack is empty: i.e. whether its size is zero.
	 *  @return bool - true if the underlying container's size is 0, false otherwise. 
	 */
    bool empty();
	/** @brief  Returns the top element in the stack. 
	 *  @return Type - value element
	 */
    Type top();

};

#include "stack.cpp"
#endif
