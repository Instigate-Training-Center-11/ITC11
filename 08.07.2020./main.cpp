#include <iostream>
#include <vector>
#include "BellmanFord.cpp"

using namespace std;

int main()
{
    cout << "Program started.\n";

    /* List that presents our graph. */
    vector<vector<pair<int, int>>> listOfPairs = myList();

    /* List of shortest path distances for node 0. */
    int node = 0;
    vector<int> distance = BellmanFordSP(listOfPairs, node);

    /* Printing the list */
    PrintShortestPath(distance, node);

    cout << endl;

    return 0;
}
