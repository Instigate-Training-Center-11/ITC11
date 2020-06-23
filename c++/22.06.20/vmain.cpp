#include <iostream>

#include "vector.cpp"
#include "vector.h"
#include "iterator.h"

int main()
{
    vector<int> vec;

    /* Add elements in the end of vector */
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);

    std::cout << "Vector after push_back" << std::endl;
    vec.print();
    std::cout << "Size = " << vec.size() << std::endl;
    std::cout << "Capacity = " << vec.capacity() << std::endl;
    std::cout << std::endl;

    std::cout << "Vector after pop_back" << std::endl;
    vec.pop_back();
    vec.print();
    std::cout << "Size = " << vec.size() << std::endl;
    std::cout << "Capacity = " << vec.capacity() << std::endl;
    std::cout << std::endl;

    std::cout << "Is vector empty?" << std::endl;
    vec.empty();
    std::cout << std::endl;

    std::cout << "Reserve vector" << std::endl;
    vec.reserve(50);
    vec.print();
    std::cout << "Size = " << vec.size() << std::endl;
    std::cout << "Capacity = " << vec.capacity() << std::endl;
    std::cout << std::endl;

    std::cout << "Print element by given index" << std::endl;
    std::cout << "2nd element is " << vec[1] << std::endl;
    std::cout << "4th element is " << vec[5] << std::endl;
    std::cout << std::endl;


    std::cout << "Shrink_to_fit vector" << std::endl;
    vec.shrink_to_fit();
    vec.print();
    std::cout << "Size = " << vec.size() << std::endl;
    std::cout << "Capacity = " << vec.capacity() << std::endl;


    return 0;
}

