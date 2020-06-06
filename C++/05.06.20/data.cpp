#include <iostream>
#include "data.hpp"

int sum = 0;

Data::Data() {
    static int count = 0;
    std::cout << "___________________________________" << std::endl;
    std::cout << "|                                 |" << std::endl;
    std::cout << "\tData " << count << " Constructor" << std::endl;
    std::cout << std::endl;
    count++;
    sum = count;
}

Data::~Data() {
    static int count = sum;
    --count;
    std::cout << "\tData " << count << " Destructor" << std::endl;
    std::cout << "|                                 |" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}