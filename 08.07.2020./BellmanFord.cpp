#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> myList()
{
    vector<vector<pair<int, int>>> listOfPairs; /* from -> to + weight */

    const int n = 6;

    for (int i = 0; i < n; i++)
    {
        /* vector to present a row, and add it to the listOfPairs */
        vector<pair<int, int>> row;
        listOfPairs.push_back(row);
    }

    /* now we nnet to fill the list */

    listOfPairs[0].push_back(make_pair(1, 6));
    listOfPairs[0].push_back(make_pair(2, 4));
    listOfPairs[0].push_back(make_pair(4, 5));

    listOfPairs[1].push_back(make_pair(2, -2));
    listOfPairs[1].push_back(make_pair(3, -1));

    listOfPairs[2].push_back(make_pair(4, -2));
    listOfPairs[2].push_back(make_pair(3, 3));

    listOfPairs[3].push_back(make_pair(5, 3));
    
    listOfPairs[4].push_back(make_pair(5, -1));
    
    listOfPairs[5].push_back(make_pair(3, 3));
    
    /* Returning the graph */
    return listOfPairs;
}

/* Finding shortest paths from "start" to all other vertices */
vector<int> BellmanFordSP(vector<vector<pair<int, int>>> &listOfPairs, int &start)
{
    vector<int> distance;

    /* Initialize all vertexes as infinite absent start */
    int n = listOfPairs.size();
    for (int i = 0; i < n; i++)
    {
        distance.push_back(999);
    }

    distance[start] = 0;

    /* calculating the shortest distance */
    // For numNodes-1...
    for (int i = 0; i < n - 1; i++)
    {
        /* For nodes as u */
        for (int u = 0; u < n; u++)
        {
            /* For nodes as v */
            for (int j = 0; j < listOfPairs[u].size(); j++)
            {
                int v = listOfPairs[u][j].first;
                int weight = listOfPairs[u][j].second;

                /* Updating the value of v when new value is least */
                if (distance[v] > distance[u] + weight)
                {
                    distance[v] = distance[u] + weight;
                }
            }
        }
    }
    return distance;
}

void PrintShortestPath(vector<int> &distance, int &start)
{
    cout << "\nPrinting the shortest paths for node " << start << ".\n";
    for (int i = 0; i < distance.size(); i++)
    {
        cout << "The distance is: " << start << " from " << i << " ---> " << distance[i] << endl;
    }
}

