#include "linkList.h"

typedef DoubleList<int>::Iterator  Iterator;
//g++ -std==c++14  main.cpp 
int main() {

    DoubleList<int> list;
    for (int i = 0; i < 10; ++i) {
        list.pushBack(i);
    }
    //DoubleList<int> list2(list);
    Iterator begin = list.begin();
    Iterator end = list.end();
    //if (end != begin) {
    //    std::cout << "no equal\n";
    //}
    list.print();
    //list.insert(begin += 1,20000);

    //if (*end == 5555) {
    //    std::cout << "equal\n";
    //}

    //begin++;
    //begin--;
    //--begin;
    //++begin;

    //list.remove(5);

    //list.erase(begin += 5);

    //std::cout << "------------------" << *begin << std::endl;

    //list2 = list;
    //list.pushBack(5);
    //DoubleList<int> list1(list);
    //list.popFront();
    //list.pushBack(5555);
    //list.popBack();
    //list.pushBack(5);
    //list.pushFront(5);
    //list.remove(1);
    //std::cout << "---------------" << list.size() << std::endl;
    //list.print();

    return 0;
}
