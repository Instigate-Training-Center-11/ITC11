#include <iostream>
#include "list.hpp"
#include "vector.hpp"

int main() {
    List list(5, 4);
    std::cout << "Declare list(Data child)" << std::endl;
    list.print();

    {
        Vector vector(5, 4);
        std::cout << "Declare vector(Data child)" << std::endl;
        vector.push_front(6);
        vector.print();
    }

    Data *s = &list;
    s -> print();

    return 0;
}