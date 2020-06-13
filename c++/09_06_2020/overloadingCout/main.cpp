#ifndef _IOSTREAM_
#define _IOSTREAM_

#include "queue.hpp"
#include "list.hpp"


int main() {

    List<char> list;
    Queue<int> obj(4);
    for (int i = 0; i < 10; ++i){
        list.insertAtIndex(i,'a' + i);
    }
    list.removeAtIndex(0);
    std::cout<< obj;
    std::cout << list;
    list[5];
    return 0;
}

#endif
