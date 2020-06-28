#include "vector.h"


typedef MyVector<int>::Iterator Iterator;

//g++ -std==c++14  main.cpp 

int main() {

    MyVector<int> vector;

    for (int i = 0; i < 5; ++i) {
        vector.PushBack(i);
    }
    std::cout<< vector[5000];
    //vector.resize(14);
    //vector.print();
    //MyVector<int> newVector(vector);
    //newVector = vector;
    //Iterator begin = vector.begin();
    //Iterator end = vector.end();
    //begin - 2;
    //std::cout << *begin++<< std::endl;
    //std::cout << *end << std::endl;
    //if (begin == end) {
    //    std::cout << "Equal" << std::endl;
    //} else {
    //    std::cout << "No Equal" << std::endl;
    //}
    //while (!vector.empty()) {
    //    vector.popBack();
    //}
    //vector.reserve(80);
    //newVector.print();
    //vector.shrinkToFit();
    //vector.popBack();
    //std::cout << "==========" << vector.getSize() << std::endl;
    //std::cout << "----------" << vector.sizeCapacity() << std::endl;
    return 0;
}
