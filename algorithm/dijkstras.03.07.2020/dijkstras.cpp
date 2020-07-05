#include<iostream>
#include<vector>
#include<set>

enum city {Seattle,SanFrancisco,Denver,LasVegas,LosAngeles,Phoenix};

typedef std::pair<int,unsigned long long> PII;
typedef std::vector<PII> VECTORPAIR;
typedef std::vector<VECTORPAIR> VVPAIR;


void DijkstrasShortestPath (int cityOne,int cityTwo, VVPAIR& graph);

int main(){

    std::vector<VECTORPAIR> graph;


    VECTORPAIR seattle = {{SanFrancisco,808}, {Denver,1316}};
    graph.push_back(seattle);


    VECTORPAIR sanFrancisco = {{Seattle,808}, {LasVegas,568}, {LosAngeles,388}};
    graph.push_back(sanFrancisco);


    VECTORPAIR denver = {{Seattle,1316}, {LasVegas,748}, {Phoenix,821}};
    graph.push_back(denver);


    VECTORPAIR lasVegas = {{SanFrancisco,568}, {Denver,748}, {LosAngeles,269}, {Phoenix,297}};
    graph.push_back(lasVegas);


    VECTORPAIR losAngeles = {{SanFrancisco,388}, {LasVegas,269}, {Phoenix,372}};
    graph.push_back(losAngeles);


    VECTORPAIR phoenix = {{Denver,821}, {LasVegas,297}, {LosAngeles,372}};
    graph.push_back(phoenix);

    DijkstrasShortestPath(Seattle, Phoenix, graph);
    std::cout <<"\n";

    return 0;
}


void DijkstrasShortestPath (int cityOne, int cityTwo, VVPAIR& graph) {
    int nodeCount = graph.size();
    const long long INF = 999999999999;
    std::vector<unsigned long long> dist(nodeCount, INF);
    std::set<PII> set_length_node;
    dist[cityOne] = 0;
    set_length_node.insert(PII(0,cityOne));
    while (!set_length_node.empty()) {

        PII top = *set_length_node.begin();
        set_length_node.erase(set_length_node.begin());
        int cityOne = top.second;
        for(auto& it : graph[cityOne]) {
            int adj_node = it.first;
            int length_to_adjnode = it.second;
            if (dist[adj_node] > length_to_adjnode + dist[cityOne]) {
                if (dist[adj_node] != INF) {
                   set_length_node.erase(set_length_node.find(PII(dist[adj_node],adj_node)));
                }
                dist[adj_node] = length_to_adjnode + dist[cityOne];
                set_length_node.insert(PII(dist[adj_node], adj_node));
            }
        }
    }
    for (int i = 0; i < nodeCount; i++) {
        switch(i) {
            case 0:
                std::cout << "Seattle(" << cityOne << ") -> Seattle(" << i << ") : " << dist[i] << " km" <<std:: endl;
                break;
            case 1:
                std::cout << "Seattle(" << cityOne << ") -> SanFrancisco(" << i << ") : " << dist[i] << " km" <<std:: endl;
                break;
            case 2:
                std::cout << "Seattle(" << cityOne << ") -> Denver(" << i << ") : " << dist[i] << " km" <<std:: endl;
                break;
            case 3:
                std::cout << "Seattle(" << cityOne << ") -> LasVegas(" << i << ") : " << dist[i] << " km" <<std:: endl;
                break;
            case 4:
                std::cout << "Seattle(" << cityOne << ") -> LosAngeles(" << i << ") : " << dist[i] << " km" <<std:: endl;
                break;
            case 5:
                std::cout << "Seattle(" << cityOne << ") -> Phoenix(" << i << ") : " << dist[i] << " km" <<std:: endl;
                break;
        }
    }

        std::cout << "\nSource Node(" << cityOne << ") -> Destination Node(" << cityTwo << ") : " << dist[cityTwo] << " km" <<std::endl;
}