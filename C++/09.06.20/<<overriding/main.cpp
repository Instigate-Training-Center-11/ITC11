#include <iostream>
#include "list.cpp"

int main() {
    List<char> list;
    list.push_back('a');
    list.push_back('b');
    list.push_back('c');
    list.push_back('d');
    list.push_back('f');
    std::cout << list;

    return 0;
}
