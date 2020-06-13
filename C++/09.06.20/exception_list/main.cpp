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

    Queue<int> myq(11, 34);
    Queue<int> myq1;

    std::cout << "this is my Queue class object" << std::endl;
    myq.print_queue();

    /* Error code 101(out of Queue, not find index) */
    try {
	    myq.set_at_index(11,-6);
    } catch (my_exception& exception){
	    std::cerr << "my exception! (" << exception.what() << ")\n";
    }

    /* Error code 202(empty Queue) */
    try {
        myq1.print_queue();
    } catch (my_exception& exception){
	    std::cerr << "my exception! (" << exception.what() << ")\n";
    }

    return 0;
}
