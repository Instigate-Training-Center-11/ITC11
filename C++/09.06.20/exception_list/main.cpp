#include <iostream>
#include "my_exception.hpp"
#include "list.hpp"
#include "queue.hpp"

int main() {
    List<char> list1(11,'f');
    List<int> list2;

    /* Error code 101(out of list, not find index) */
	try {
	    list1.set_at_index('a',-6);
    } catch (my_exception& exception){
	    std::cerr << "my exception! (" << exception.what() << ")\n";
    }

    /* Error code 202(empty list) */
    try {
        list2.print();
    } catch (my_exception& exception){
	    std::cerr << "my exception! (" << exception.what() << ")\n";
    }

    list1.print();

    return 0;
}
