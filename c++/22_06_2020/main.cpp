#include "vector.h"

int main() {
    MyVector<int> vector;
    for (int i = 1; i < 81; ++i) {
        vector.PushBack(i);
    }
    vector.print();
    std::cout << "==========" << vector.getSize() << std::endl;
    std::cout << "----------" << vector.sizeCapacity() << std::endl;
    return 0;
}