#include <iostream>
#include "list.hpp"
#include "queue.hpp"

int main() {
    Queue q;

    std::cout << "After push back  in queue" << std::endl;
    q.pushBack(5);
    q.pushBack(1);
    q.pushBack(5);
    q.display();

    std::cout << "After push front in queue" << std::endl;
    q.pushFront(1);
    q.pushFront(3);
    q.pushFront(4);
    q.display();

    return 0;
}

