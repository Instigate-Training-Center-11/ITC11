#include "list.hpp"

/*Here is declared class Queue.The inherited class inherits all its functions from the base class to the private type*/
class Queue : private List {
    public:
        /*Default constructor*/
        Queue();
        /*Insert item*/
        void insertItem(int element);
        /*Delete item by index*/
        void deleteItem();
        /*Display queue*/
        void display();
        /*Destructor*/
        ~Queue();
};

#endif
