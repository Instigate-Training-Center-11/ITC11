#include "vector.h"

int main() {
    MyVector<int> vector;
    for (int i = 0; i < 10; ++i) {
        vector.PushBack(i);
    }
    vector.print();
    MyVector<int>::Iterator begin = vector.begin();
    MyVector<int>::Iterator end = vector.end();
    //begin + 12;
    std::cout << "----------------------\n";
    std::cout<<"======== " << *vector[1] << std::endl;;
    std::cout << "begin = " << *begin << std::endl;
    std::cout << "end = " << *end << std::endl;
    std::cout << "end = " << *end-- << std::endl;
    std::cout << "end = " << *end << std::endl;
    std::cout << "begin = " << *(--end) << std::endl;
    //while (!vector.empty()) {
    //    vector.popBack();
    //}
    //vector.reserve(80);
    //vector.shrinkToFit();
    //vector.popBack();
    //std::cout << "==========" << vector.getSize() << std::endl;
    //std::cout << "----------" << vector.sizeCapacity() << std::endl;
    return 0;
}