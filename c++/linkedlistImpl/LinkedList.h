#ifndef LIST_H
#define LIST_H
#include "node.h"

class LinkedLiist {
/* we are creating the type with our struct */
node::node* nodePtr;
/* for novigation in the linkedList we need have variables */
/* head- for firs, current - for current and temp for temperory part */
nodePtr head;
nodePtr current;
nodePtr temp;
/*we need functions for input, delete parts or nodes and to print */
/* the functions will be public for accessing aut of this class too */
public:
/* LinkedLiist(); */
void AddNode (int addData);
void DeletNode(int delData);
void PrintList();
};
/* #endif; */