
#include <iostream>
#include <set>
#include <climits>
#include <unordered_map>
#include <map>
#include <list>
using namespace std;

template <typename G>
class Graph
{
    /* Sorting is not important at this time, so we use unordered_map */
    unordered_map<G, list<pair<G, int>>> map;

public:
    void addEdge(G u, G v, int distance, bool direct = true)
    {
        map[u].push_back(make_pair(v, distance)); /* for exsample Moskow - > Yerevan, 2 */
        if (direct)
        {
            map[v].push_back(make_pair(u, distance));
        }
    }

    /* We need to take variable start as first step , as first peak */
    void algDijik(G start)
    {
        unordered_map<G, int> distance;

        /* set all distances as infinity */
        for (auto i : map)
        {
            distance[i.first] = INT_MAX;
        }

        /* create a set to find a node with the min distance */
        set<pair<int, G>> s;

        distance[start] = 0;
        s.insert(make_pair(0, start));

        while (!s.empty())
        {
            auto p = *(s.begin());
            G node = p.second;

            int nodedistance = p.first;
            s.erase(s.begin());

            for (auto childPair : map[node])
            {
                if (nodedistance + childPair.second < distance[childPair.first])
                {
                    /* we need to remove the old pair*/
                    G dest = childPair.first;
                    auto f = s.find(make_pair(distance[dest], dest));
                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                    /* and insert the new pair */

                    distance[dest] = nodedistance + childPair.second;
                    s.insert(make_pair(distance[dest], dest));
                }
            }
        }
        /* print distance from all nodes from start */
        for (auto d : distance)
        {

            cout << d.first << " is far from " << start + "---> " << d.second << endl;
        }
    }
};