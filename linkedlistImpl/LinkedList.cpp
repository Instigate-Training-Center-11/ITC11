#include <iostream>
#include "LinkedList.h"
#include "node.h"

/* creating the construkter of class LinkedList */
LinkedList::LinkedList() {    
    head = NULL;
    current = NULL;
    temp = NULL;
}

/* to add a new node, we must take the new mamory part and */
/* move the pointer in the current part if it exists in the new part */
/* and we need to check whether the first part or the head exists or does not exist */
/* if the head does not exist, the new part becomes the head, or the head exists, the head pointer is fixed to */
/* The new side of the node in the mampry gland */

void LinkedList::AddNode (int addData) {
    nodePtr n = new node;
    n->data = addData;

    if (head != NULL){
        current = head;
        while (current->newxt !=NULL) {
            current = current->next;
        }
        current->newt = n;
   } 
   else {
       head = n;
   }
}
/* To remove each node of the list of links, we need to start our steps from the head */
/* We will find the node. If the node does not have a pointer in the next part, */
/* this is the last. We can remove the value. If it has a pointer, with the help of an intermediate variable we do the following. */
/* Move pointer from the node to the next node. It already refers to the next node. After that, delete value. */
void LinkedList::DeletNode (int delData) {
    nodePtr delPtr = NULL;
    temp = head;
    current = head;
    while (current != NULL && current->data != delData){
        temp = current;
        current = current->next;
    }
    if (current == NULL) {
    std::cout << delData << "You are aut of the range of Linkedlist";
}
else {
    delPtr = current;
    current = current->next;
    temp->next = current;
    delPtr = NULL;
    std::cout << "The value was deleted";
    }
}
/* Iterate LinkedList and print all values of list */
void LinkedList::PrintList(){
    current = head;
    while (current !=NULL){
        std::cout << current->data << " ";
        current = current->next;
    }
}
