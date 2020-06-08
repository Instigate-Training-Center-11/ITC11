#include <iostream>
#include "queue.h"
#include "node.cpp"
#include "list.cpp"
#include "queue.cpp"

int main() {
    /* Adding elements from the beginning of the list and by given index and prints list. */
    List<double> listDouble;
    listDouble.pushFront(17.2);
    listDouble.pushFront(18.2);
    listDouble.pushFront(19.2);
    listDouble.insert(20.2, 0);
    listDouble.insert(21.2,3);
    
    std::cout << "---------------LIST FOR TYPE DOUBLE---------------" << std::endl << std::endl;
    listDouble.show();
    std::cout << "Size: " << listDouble.getsize() << std::endl;

    /* We delete items from the list, as well as from this item that we select and prints list. */
    listDouble.popFront();
    listDouble.remove(3);
    listDouble.show();
    std::cout << "Size: " << listDouble.getsize() << std::endl;

    /* Use the loop to go through the entire list and print all the elements of this list. */
    for (int i = 0; i < listDouble.getsize(); i++) {
        std::cout << listDouble[i] << std::endl; 
    }

    /* Delete the entire sheet and print its size */
    listDouble.clear();
    std::cout << "Size: " << listDouble.getsize() << std::endl;

    /* Adding elements from the beginning of the list and by given index and prints list. */
    List<std::string> listString;
    listString.pushFront("aaaaaa");
    listString.pushFront("xxxxx");
    listString.pushFront("iiiii");
    listString.insert("gggggg", 0);
    listString.insert("fcccccc",3);
    
    std::cout << "---------------LIST FOR TYPE STRING---------------" << std::endl << std::endl;
    listString.show();
    std::cout << "Size: " << listString.getsize() << std::endl;

    /* We delete items from the list, as well as from this item that we select and prints list. */
    listString.popFront();
    listString.remove(3);
    listString.show();
    std::cout << "Size: " << listString.getsize() << std::endl;

    /* Use the loop to go through the entire list and print all the elements of this list. */
    for (int i = 0; i < listString.getsize(); i++) {
        std::cout << listString[i] << std::endl; 
    }

    /* Delete the entire sheet and print its size */
    listString.clear();
    std::cout << "Size: " << listString.getsize() << std::endl;

    /*
    Creating a queue and adding elements to it,
    then printing all the elements at the end.
    */
    Queue<float> queueFloat;
    queueFloat.pushBeackQueue(15.5);
    queueFloat.pushBeackQueue(25.5);
    queueFloat.pushBeackQueue(35.5);
    queueFloat.pushBeackQueue(45.5);
    queueFloat.pushBeackQueue(55.5);

    std::cout << "---------------QUEUE FOR TYPE FLOAT---------------" << std::endl << std::endl;
    queueFloat.showQueue();
    std::cout << std::endl;

    /* Removing elements from queue and printing. */
    queueFloat.popFrontQueue();
    queueFloat.popFrontQueue();
    queueFloat.showQueue();

        /*
    Creating a queue and adding elements to it,
    then printing all the elements at the end.
    */
    Queue<int> queueInt;
    queueInt.pushBeackQueue(1);
    queueInt.pushBeackQueue(2);
    queueInt.pushBeackQueue(3);
    queueInt.pushBeackQueue(4);
    queueInt.pushBeackQueue(5);

    std::cout << "---------------QUEUE FOR TYPE INT---------------" << std::endl << std::endl;    
    queueInt.showQueue();
    std::cout << std::endl;

    /* Removing elements from queue and printing. */
    queueInt.popFrontQueue();
    queueInt.popFrontQueue();
    queueInt.showQueue();

    return 0;
}