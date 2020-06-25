#include <iostream>
#include "binery_tree.h"

int main() {
    Tree bin;
    bin.insert(10);
    bin.insert(7);
    bin.insert(9);
    bin.insert(12);
    bin.insert(6);
    bin.insert(14);
    bin.insert(3);
    bin.insert(11);
    bin.insert(4);
    bin.insert(1);

    /*
     * Binery tree { 10,  7,  9, 12, 6, 14, 3, 11, 4, 1 }
     * By indexes  (  0,  1,  2,  3, 4,  5, 6,  7, 8, 9 )
     *
     *                      1 0
     *                     /   \
     *                    7     12
     *                   / \   /  \
     *                  6   9 11   14
     *                 /
     *                3
     *               / \
     *              1   4
     */

    std::cout << "Index of value 10  = " << bin.search_by_value(10) << std::endl;
    std::cout << "Index of value 7 = " << bin.search_by_value(7) << std::endl;
    std::cout << "Index of value 9  = " << bin.search_by_value(9) << std::endl;
    std::cout << "Index of value 12  = " << bin.search_by_value(12) << std::endl;
    std::cout << "Index of value 6 = " << bin.search_by_value(6) << std::endl;
    std::cout << "Index of value 14 = " << bin.search_by_value(14) << std::endl;
    std::cout << "Index of value 3 = " << bin.search_by_value(3) << std::endl;
    std::cout << "Index of value 11 = " << bin.search_by_value(11) << std::endl;
    std::cout << "Index of value 4 = " << bin.search_by_value(4) << std::endl;
    std::cout << "Index of value 1 = " << bin.search_by_value(1) << std::endl;


    std::cout << "Size = " << bin.get_size() << std::endl;
    return 0;
}