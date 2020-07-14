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
		/** @private  
		 * 
		 */
        bool operator!=(const Iterator& itr) const {
            return nodePtr != itr.nodePtr;
        }

        bool operator==(const Iterator& itr) const {
            return nodePtr == itr.nodePtr;
        }

        Type& operator*() const {
            return nodePtr->value;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            if (nodePtr->Next == nullptr) {
                std::cout << "You are already at the end of the list" << std::endl;
                return temp;
            }

            nodePtr = nodePtr->Next;
            return temp;
        }

        Iterator operator++(void) {
            if (nodePtr->Next == nullptr) {
                std::cout << "You are already at the end of the list" << std::endl;
                return nodePtr;
            }

            nodePtr = nodePtr->Next;
            return nodePtr;
        }

        Iterator operator--(int) {
            Iterator temp = *this;
            if (nodePtr->Prev == nullptr) {
                std::cout << "You are already at the beginning of the list" << std::endl;
                return temp;
            }

            nodePtr = nodePtr->Next;
            return temp;
        }

        Iterator operator--(void) {
            if (nodePtr->Prev == nullptr) {
                std::cout << "You are already at the beginning of the list" << std::endl;
                return nodePtr;
            }

            nodePtr = nodePtr->Next;
            return nodePtr;
        }

        Iterator operator+=(unsigned int diff) {
            while (diff != 0) {
                if (nodePtr->Next == nullptr) {
                    std::cout << "You went too far !!!" << std::endl;
                    return nullptr;
                }
                nodePtr = nodePtr->Next;
                --diff;
            }
            return nodePtr;
        }

    };

    /**@brief Removes from the list container either a single element 
	 *@param Iterator - position
	 *@return  Iterator - position 
	 */
    auto erase(Iterator position);
    /**@brief The container is extended by inserting new elements before the element at the specified position.
     *@param Iterator -  position 
     *@param const Type& - nodeValue
     *@return  Iterator - position 
     */
    auto insert(Iterator position,const Type& nodeValue);
    /**@brief Assigns new contents to the container, replacing its current contents,
	 *and modifying its size accordingly.
	 *@param const DoubleList& - object
	 *@return const DoubleList& - new object 
	 */
    DoubleList<Type>& operator= (const DoubleList& object);
    /* Removes from the container all the elements that compare equal to NodeValue.
     * This calls the destructor of these objects and reduces the container size
     * by the number of elements removed. */
    void remove(const Type& nodeValue);
    /* Inserts a new element at the beginning of the list, right before its current
     * first element. The content of NodeValue is copied (or moved) to the inserted element. */
    void pushFront(Type NodeValue);
    /* Removes the first element in the list container, effectively reducing its size by one. */
    void popFront(void);
    /* Returns whether the list is empty (i.e. whether its size is 0). */
    bool empty(void) const;
    /* Removes the last element in the list, effectively reducing the container size by one. */
    void popBack(void);
    /* Returns the number of elements in the list.
     * Member type size_type is an unsigned integral type. */
    unsigned int size(void) const;
    /* printing the custom  list */
    void print(void) const;
    /* Adds a new element at the end of the list, after its current last element. */
    void pushBack(Type NodeValue = 0);
    /* Constructs a container with n elements. Each element is a copy of NodeValue. */
    DoubleList(unsigned int countNode = 0 , Type NodeValue = 0);
    /* Constructs a container with a copy of each of the elements in x, in the same order. */
    DoubleList(const DoubleList<Type> &object);
    /* Destroys the container object. */
    ~DoubleList();
    Iterator begin(void) const {
        return Iterator(head);
    }
    Iterator end(void) const {
        return Iterator(tail);
    }
};

#include "linkList.cpp"
#endif
