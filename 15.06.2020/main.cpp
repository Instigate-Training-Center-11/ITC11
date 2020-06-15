#include <iostream>

#include "list.h"

int main() {
    MyList list;

    list.PushFront(2);
    list.PushFront(1);
    list.PushBack(4);
    list.InsertElement(2, 3);
    list.GetElement(0);
    list.PrintList();
    
    return 0;
}