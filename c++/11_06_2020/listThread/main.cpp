#ifndef _IOSTREAM_
#define _IOSTREAM_

#include "queue.hpp"
#include "list.hpp"


int main() {

    List<int> list;
    Queue<int> obj(4);
    for (int i = 0; i < 10; ++i){
        list.insertAtIndex(i,i);
    }
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << "threadId = " << this_id <<"\n";
    list.printList();
    std::thread th([&]() {
        list.deleteThread(5);
    });
    th.join();
    list.printList();
    std::thread th1([&]() {
        list.insertAtIndexThread(8,50);
    });
    th1.join();
    //list.removeAtIndex(0);
    //list.printList();
    //th1.join();
    //list.clear();
    //obj.push(8);
    //obj.show();
    //obj.size();
    //obj.pop();
    //obj.show();
    list.printList();
    //list.insertAtIndex(0,1000);
    //list.setAtIndex(5,20);
    //list.removeAtIndex(8);
    //list.getSize();
    //list[5];
    return 0;
}

#endif
