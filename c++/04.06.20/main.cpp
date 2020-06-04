#include <iostream>
#include "list.hpp"

int main()
{
    List l;
    l.add(1,0);
    l.add(5,1);
    l.add(1,2);
    l.add(3,3);
    l.add(4,4);
    l.printf();
    std::cout << l.getElement(2) << std::endl;
    List l1(l);
    l1.printf();
    l.remove(0);
    l.printf();
    l.remove(2);
    l.printf();
    return 0;
}

