#include <iostream>

#include "queue.h"

int main() {
    Queue queue;
    queue.pushBack(6);
    queue.pushBack(5);
    queue.pushBack(4);

    queue.pushFront(3);
    queue.pushFront(2);
    queue.pushFront(1);

    queue.push(0, 0);
    queue.show();

    return 0;
}