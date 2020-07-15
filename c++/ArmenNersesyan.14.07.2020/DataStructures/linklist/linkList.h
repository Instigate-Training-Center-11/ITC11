#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include <iostream>

template<typename Type>

class DoubleList {
    struct Node {
        Node* Next;
        Node* Prev;
        Type value;
    };

    Node* tail;
    Node* head;
    unsigned int sizeList;

public:

    class Iterator {
    private:
        friend class  DoubleList;
        Node *nodePtr;
        Iterator(Node* newPtr) : nodePtr(newPtr) { }
    public:
        Iterator() : nodePtr(nullptr) {}

        bool operator!=(const Iterator& itr) const;
        bool operator==(const Iterator& itr) const;
        Type& operator*() const;
        Iterator operator++(int);
        Iterator operator++(void);
        Iterator operator--(int);
        Iterator operator--(void);
        Iterator operator+=(unsigned int diff);

    };

    /** @brief Removes from the list container either a single element 
	 *  @param Iterator - position
	 *  @return  Iterator - position 
	 */
    auto erase(Iterator position);
    /** @brief The container is extended by inserting new elements before the element at the specified position.
     *  @param Iterator -  position 
     *  @param const Type& - nodeValue
     *  @return  Iterator - position 
     */
    auto insert(Iterator position,const Type& nodeValue);
    /** @brief Assigns new contents to the container, replacing its current contents,
	 *  and modifying its size accordingly.
	 *  @param const DoubleList& - object
	 *  @return DoubleList<Type>& - new object 
	 *  @see Ref & object
	 */
    DoubleList<Type>& operator= (const DoubleList& object);
    /** @brief Removes from the container all the elements that compare equal to NodeValue.
     *  This calls the destructor of these objects and reduces the container size
     *  by the number of elements removed. 
	 *  @param  const DoubleList& - object
	 */
    void remove(const Type& nodeValue);
    /** @brief Inserts a new element at the beginning of the list, right before its current
     *  first element. The content of NodeValue is copied (or moved) to the inserted element.
	 *  @param Type - nodeValue  
	 */
    void pushFront(Type NodeValue);
    /** @brief Removes the first element in the list container, effectively reducing its size by one. 
	 */
    void popFront(void);
    /** @brief Returns whether the list is empty (i.e. whether its size is 0). 
	 *	@return bool - true or false
	 */
    bool empty(void) const;
    /** @brief Removes the last element in the list, effectively reducing the container size by one. 
	 */
    void popBack(void);
    /** @brief Returns the number of elements in the list.
     *  Member type size_type is an unsigned integral type. 
	 *  @return  unsigned int - size current list
	 */
    unsigned int size(void) const;
    /** @brief printing the custom  list */
    void print(void) const;
    /** @brief Adds a new element at the end of the list, after its current last element. 
	 *  @param Type - NodeValue
	 */
    void pushBack(Type NodeValue = 0);
    /** @brief Constructs a container with n elements. Each element is a copy of NodeValue. default parameters equal 0 
	 *	@param unsigned int - Node count 
	 *	@param  Type - Node value
	 */
    DoubleList(unsigned int countNode = 0 , Type NodeValue = 0);
    /** @brief Constructs a container with a copy of each of the elements in x, in the same order. 
	 *  @param const DoubleList<Type> @see Ref & - object
	 */
    DoubleList(const DoubleList<Type> &object);
    /** @brief Destroys the container object. 
	 */
    ~DoubleList();
	/** @brief iterator to head the current list 
	 *  @return Iterator - link to the head linked list;
	 */
    Iterator begin(void) const {
        return Iterator(head);
    }
	/** @brief iterator to tail the current list
     *  @return Iterator - link to the tail linked list;
     */
    Iterator end(void) const {
        return Iterator(tail);
    }
};

#include "linkList.cpp"
#endif
