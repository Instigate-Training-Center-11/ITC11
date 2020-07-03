#include <iostream>
#include "DijkstrasAlg.cpp"


int main()
{
    Graph<string> eurasia;
    eurasia.addEdge("Moskow", "Yerevan", 1);
    eurasia.addEdge("Moskow", "Tbilisi", 4);
    eurasia.addEdge("Tbilisi", "Yerevan", 2);
    eurasia.addEdge("Tbilisi", "Kiew", 8);
    eurasia.addEdge("Peterburg", "Gelengik", 2);
    eurasia.addEdge("Kiew", "Peterburg", 3);
    eurasia.addEdge("Gelengik", "Yerevan", 1);
    eurasia.addEdge("Kiew", "Athens", 4);
    eurasia.addEdge("Peterburg", "Athens", 5);

    eurasia.algDijik("Moskow");

    return 0;
}