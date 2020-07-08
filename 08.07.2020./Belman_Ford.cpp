#include <iostream>
using namespace std;

// easy

#define MAXE 10000
#define MAXN 100

int main()
{
    int node, edge, src;
    int d[MAXN], edgeU[MAXE], edgeV[MAXE], edgeW[MAXE];
    cin >> node >> edge >> src;

    for (int i = 1; i < node; i++)
        d[i] = 99999;
    d[src] = 0; // distance to source is 0
    for (int i = 0; i < edge; i++)
    {
        cin >> edgeU[i] >> edgeV[i] >> edgeW[i];
    }
    bool negCycle = false;
    for (int step = 0; step < node - 1; step++)
    {
        bool updated = false;
        for (int i = 0; i < edge; i++)
        {
            int u = edgeU[i], v = edgeV[i], w = edgeW[i];
            if (d[u] + edgeW[i] < d[v])
            {
                d[v] = d[u] + edgeW[i];
            }
        }
    }

    for (int i = 0; i < edge; i++)
    {
        int u = edgeU[i], v = edgeV[i], w = edgeW[i];
        if (d[u] + edgeW[i] < d[v])
        {
            negCycle = true;
        }
    }

    if (!negCycle)
    {
        cout << "Distance to node: " << endl;
        for (int i = 0; i < node; i++)
        {
            cout << i << "  " << d[i] << endl;
        }
    }
    else
        cout << "It is not possible" << endl;
    return 0;
}