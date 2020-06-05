#include <cstdlib>
#include "LinkedList.h"
#include "node.h"

int main () {
LinkedList LS;

LS.AddNode (5);
LS.AddNode (3);
LS.AddNode (2);
LS.PrintList();

LS.DeletNode(5);
LS.PrintList();

LS.DeletNode(3);
LS.DeletNode(2);
LS.PrintList();
}