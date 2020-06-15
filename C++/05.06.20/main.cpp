#include <iostream>
#include "list.hpp"
#include "queue.hpp"

int main() {
    Queue que;
    que.push_back_queue(777);
    que.push_back_queue(777);
    que.push_back_queue(777);
    que.pop_front_queue();
    que.print_queue();
    return 0;
}