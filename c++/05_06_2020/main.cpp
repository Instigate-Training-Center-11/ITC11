#ifndef _IOSTREAM_
#define _IOSTREAM_

#include "queue.hpp"
#include "list.hpp"

int main() {

    List list;
    Queue obj(4);
    for (int i = 0; i < 10; ++i){
        list.insertAtIndex(i,i);
    }

    //std::cout << object.Size() << std::endl;
    /* index,value */
        list[8000];
        //std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
    //list.printList();
    list.removeAtIndex(0);
    list.printList();
    //list.clear();
    //obj.push(8);
    //obj.show();
    //obj.size();
    //obj.pop();
    //obj.show();
    //list.printList();
    //list.insertAtIndex(0,1000);
    //list.setAtIndex(5,20);
    //list.removeAtIndex(8);
    //list.getSize();
    //list[5];

    return 0;
}

#endif
