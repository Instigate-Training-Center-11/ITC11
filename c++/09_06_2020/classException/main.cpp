#ifndef _IOSTREAM_
#define _IOSTREAM_

#include "queue.hpp"
#include "list.hpp"

int main() {
    int countQ = -10;
    int countL = -10;
    try {
        if (countQ < 0) {
            throw customException("Error negative number");
        }
        if (countL < 0) {
            throw customException("Error negative number");
        }
        List<int> list;
        Queue<int> obj(-20);
        for (int i = 0; i < 10; ++i){
            list.insertAtIndex(i,i);
            obj.insertAtIndexQ(i,i);
        }
        //list[50];
        //list.printList();
        //list.removeAtIndex(-2);
        //list.printList();
        //list.clear();
        //obj.push(20);
        //obj.show();
        //obj.size();
        //obj.pop();
        //obj.clearQ();
        //list.insertAtIndex(-10,1000);
        //list.setAtIndex(-22,20);
        //list.removeAtIndex(8);
        //list.getSize();
        //list[5];
    } catch (customException& Err){
        std::cout << Err.what () << std::endl;
    }
    return 0;
}

#endif
