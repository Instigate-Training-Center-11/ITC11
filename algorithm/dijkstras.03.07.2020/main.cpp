#include<iostream>
#include<vector>
#include<set>

enum city {Seattle,SanFrancisco,Denver,LasVegas,LosAngeles,Phoenix};

typedef std::pair<int,unsigned long long> PII;
typedef std::vector<PII> VECTORPAIR;
typedef std::vector<VECTORPAIR> VVPAIR;


void DijkstrasShortestPath (int source_node, int node_count, VVPAIR& graph);

int main(){

    std::vector<VECTORPAIR> graph;
    /* 0-1(260) 0-3(140) 0-2(180) 1-2(300) 2-3()*/
    // Node 0: <1,260> <2,190> <3,670>

    VECTORPAIR seattle = {{SanFrancisco,808}, {Denver,1316}};
    graph.push_back(seattle);

     // Node 1: <0,5> <2,3> <4,8>
    VECTORPAIR sanFrancisco = {{Seattle,808}, {LasVegas,568}, {LosAngeles,388}};
    graph.push_back(sanFrancisco);

    // Node 2: <0,1> <1,3> <3,2> <4,1>
    VECTORPAIR denver = {{Seattle,1316}, {LasVegas,748}, {Phoenix,821}};
    graph.push_back(denver);

    // Node 3: <0,4> <2,2> <4,2> <5,1>
    VECTORPAIR lasVegas = {{SanFrancisco,568}, {Denver,748}, {LosAngeles,269}, {Phoenix,297}};
    graph.push_back(lasVegas);

    // Node 4: <1,8> <2,1> <3,2> <5,3>
    VECTORPAIR losAngeles = {{SanFrancisco,388}, {LasVegas,269}, {Phoenix,372}, {5,3}};
    graph.push_back(losAngeles);

    // Node 5: <3,1> <4,3>
    VECTORPAIR phoenix = {{Denver,821}, {LasVegas,297}, {LosAngeles,372}};
    graph.push_back(phoenix);

    int node_count  = 6;
    int source_node = 0;

    DijkstrasShortestPath(source_node, node_count, graph);
    std::cout <<"\n";

    source_node = 5;
    DijkstrasShortestPath(source_node, node_count, graph);

    return 0;
}


void DijkstrasShortestPath (int source_node, int node_count, VVPAIR& graph) {
     // Assume that the distance from source_node to other nodes is infinite 
    // in the beginnging, i.e initialize the distance vector to a max value
    const long long INF = 999999999999;
    std::vector<unsigned long long> dist(node_count, INF);
    std::set<PII> set_length_node;
    // Distance from starting vertex to itself is 0
    dist[source_node] = 0;
    set_length_node.insert(PII(0,source_node));

    while (!set_length_node.empty()) {

        PII top = *set_length_node.begin();
        set_length_node.erase(set_length_node.begin());

        int source_node = top.second;

        for(auto& it : graph[source_node]) {

            int adj_node = it.first;
            int length_to_adjnode = it.second;

            // Edge relaxation
            if (dist[adj_node] > length_to_adjnode + dist[source_node]) {
                // If the distance to the adjacent node is not INF, means the pair <dist, node> is in the set
                // Remove the pair before updating it in the set.
                if (dist[adj_node] != INF) {
                   set_length_node.erase(set_length_node.find(PII(dist[adj_node],adj_node)));
                }
                dist[adj_node] = length_to_adjnode + dist[source_node];
                set_length_node.insert(PII(dist[adj_node], adj_node));
            }
        }
    }

    //for (int i = 0; i < source_node; i++) {
    //    switch(i) {
    //        case 0:
    //            std::cout << "(" << source_node << ")" << "Phoenix ->" << " Seattle(" << i << ") : " << dist[i] << "km\n";
    //            break;
    //        case 1:
    //            std::cout << "SanFrancisco(" << i << ") : " << dist[i] << "km\n";
    //            break;
    //        case 2:
    //            std::cout << "Denver(" << i << ") : " << dist[i] << "km\n";
    //            break;
    //        case 3:
    //            std::cout << "LasVegas(" << i << ") : " << dist[i] << "km\n";
    //            break;
    //        case 4:
    //            std::cout << "LosAngeles(" << i << ") : " << dist[i] << "km\n";
    //            break;
    //        case 5:
    //            std::cout << "Phoenix(" << i << ") : " << dist[i] << "km\n";
    //            break;
    //    }
    //}

    for (int i=0; i<node_count; i++) {
        std::cout << "Source Node(" << source_node << ") -> Destination Node(" << i << ") : " << dist[i] <<std:: endl;
    }
}

