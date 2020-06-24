#include "vector.h"

int main() {
    MyVector<int> vector(5);
    std::cout << "----------" << vector.sizeCapacity() << std::endl;
    for (int i = 0; i < 25; ++i) {
        vector.PushBack(i);
    }
    //while (!vector.empty()) {
    //    vector.popBack();
    //}
    vector.reserve(80);
    vector.print();
    vector.shrinkToFit();
    //vector.popBack();
    std::cout << "==========" << vector.getSize() << std::endl;
    std::cout << "----------" << vector.sizeCapacity() << std::endl;
    return 0;
}