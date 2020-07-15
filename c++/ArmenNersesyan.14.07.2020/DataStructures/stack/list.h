#ifndef _LIST_H_
#define _LIST_H_

template <typename Type>

class List {
private:
    unsigned int size;
    struct Node
    {
        Node *next;
        Type value;
    };
    Node *head;

public:
    /** @brief default constructor 
	 */
    List(void);
    /** @brief Parameterized constructor, create a sheet with size = count  
	 * @param unsigned int - count
	 */
    List(unsigned int count);
	/** @brief Returns the number of elements in the list.
     *  Member type size_type is an unsigned integral type.
     *  @return  unsigned int - size current list
     */
    unsigned int getSize(void) const;
    /** @brief Remove element by index 
	 *	@param unsigned int - index
	 */
    void removeAtIndex(unsigned int);
    /** @brief Insert element by index (adding new node)
	 *  @param unsigned int - index
	 *  @param Type int - value
	 */
    void insertAtIndex(unsigned int, Type);
    /** @brief Set element by index (modifies value node)
	 *  @param unsigned int - index
	 *  @param Type int - value
	 */
    void setAtIndex(unsigned int, Type);
    /** @brief Get element by index 
	 * @param unsigned int - index
	 * @return Type - value
	 */
    Type operator[](unsigned int) const;
    /** @brief Print the current list 
	 */
    void printList(void) const;
    /** @brief Remove all elements from the list 
	 */
    void clear(void);
	/** @todo
     */
    Type back(void);
	/** @brief Returns whether the list is empty (i.e. whether its size is 0).
     *  @return bool - true or false
     */
    bool empty(void);
	/** @brief Constructs a container with n elements. Each element is a copy of NodeValue. default parameters equal 0
     *  @param unsigned int - Node count
     *  @param  Type - Node value
     */
    void pushBack(Type value);
	/** @brief Removes the last element in the list, effectively reducing the container size by one.
     */
    void popBack();
    /** @brief Destructor 
	 */
    ~List(void);
};

#include "list.cpp"
#endif
