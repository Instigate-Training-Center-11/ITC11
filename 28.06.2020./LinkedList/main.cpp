#include <iostream>
#include "LinkedList.cpp"

int main() {
    struct Node *secondHead;
    struct Node *head = new Node;
    
    nodeInit(head, 5);
    display(head);

    addNode(head, 10);
    display(head);

    addNode(head, 15);
    display(head);

    addNode(head, 20);
    display(head);

    insertFront(&head, 25);
    display(head);

    int numDel = 5;
    Node *ptrDelete = searchNode(head,numDel);
    if(deleteNode(&head, ptrDelete)) 
    cout << "Node "<< numDel << " deleted!\n";
    display(head);

    cout << "The list is reversed\n";
    reverse(&head);
    display(head);

    cout << "The list is copied\n";
    copyLinkedList(head,&secondHead);
    display(secondHead);

    numDel = 35;
    ptrDelete = searchNode(secondHead,numDel);
    if(deleteNode(&secondHead, ptrDelete)) {
        cout << "Node "<< numDel << " deleted!\n";
        cout << "The new list after the delete is\n";
        display(secondHead);
    }
       
    cout << "Deleting the copied list\n";
    deleteLinkedList(&secondHead);
    display(secondHead);
    return 0;
}