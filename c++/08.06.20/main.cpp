#include <iostream>
#include "list.hpp"
#include "queue.hpp"
#include "list.cpp"
#include "queue.cpp"
int main()
{
    List<int> l;
    l.push_back(1);
    l.push_back(5);
    l.push_back(1);
    l.push_back(3);
    l.push_back(4);
    l.printf();
    l.pop_front();
    l.printf();
    l.pop_front();
    l.printf();

    Queue<double> Q;
    Q.insertItem(50.2);
    Q.insertItem(24.3);
    Q.insertItem(25.1);
    Q.insertItem(32.5);
    Q.insertItem(10.3);
    Q.display();
    Q.deleteItem();
    Q.deleteItem();
    Q.display();
    return 0;
}

