#include<iostream> 

int main() {
    Queue queue;
    int value;
    int operation;
 
  do {
    std::cout << "Enter the number of the optin. Enter 0 to exit." << std::endl;
    /* Show our functions */
    std::cout << "isEmpty()" << std::endl;
    std::cout << "isFull()" << std::endl;
    std::cout << "display()" << std::endl;
   
    std::cin >> operation;
    /* Give numbers for functions, that will be display the output of function */
    /* and exit the programm, when te number is 0 */ 
    switch (operation) {
    case 0:
        break;
    case 1:
        if (queue.isEmpty())
        std::cout << "Queue is Empty" << std::endl;
        else
        std::cout << "Queue is not Empty" << std::endl;
        break;
    case 2:
        if (queue.isFull())
        std::cout << "Queue already is Full" << std::endl;
        else
        std::cout << "Queue is still not Full" << std::endl;
        break;
    case 3:
        std::cout << "Display Function Called - " << std::endl;
        queue.display();
        break;
        default:
        std::cout << "Enter Proper Option number " << std::endl;
    } 
} while (operation != 0);
    return 0;
}
