#include "list.hpp"

#ifndef QUEUE_H
#define QUEUE_H
/*Here is declared class Queue.The inherited class inherits all its functions from the base class to the private type*/
template <typename T>
class Queue : private List<T> {
    public:
        /*Default constructor*/
        Queue();
        /*Insert item*/
        void insertItem(T element);
        /*Delete item by index*/
        void deleteItem();
        /*Display queue*/
        void display();
        /*Destructor*/
        ~Queue();
};

#endif
