#ifndef _IOSTREAM_
#define _IOSTREAM_

#include "queue.hpp"
#include "list.hpp"

int main()
{

    List<int> list;
    for (int i = 0; i < 9; ++i)
    {
        list.insertAtIndex(i, i);
    }
    //std::cout << object.Size() << std::endl;
    object.printQ();
    /* index,value */
    //list[5];
    list.printList();
    list.clear();
    //list.printList();
    //list.insertAtIndex(0,1000);
    //list.setAtIndex(5,20);
    //list.removeAtIndex(8);
    //list.getSize();
    //list[5];

    return 0;
}

#endif
