#include "dijkstras.h"

void DijkstrasShortestPath (int cityOne, int cityTwo, VVPAIR& graph) {
    int nodeCount = graph.size();
    std::vector<int> pointArray;
    const long long INF = 999999999999;
    std::vector<unsigned long long> dist(nodeCount, INF);
    std::vector<PII> distWAy(nodeCount);
    PII data = *distWAy.begin();
    std::set<PII> setLengthNode;
    dist[cityOne] = 0;
    setLengthNode.insert(PII(0,cityOne));
    while (!setLengthNode.empty()) {

        PII top = *setLengthNode.begin();
        setLengthNode.erase(setLengthNode.begin());
        int cityOne = top.second;
        for(auto& it : graph[cityOne]) {
            int adjNode = it.first;
            int length_to_adjnode = it.second;
            if (dist[adjNode] > length_to_adjnode + dist[cityOne]) {
                if (dist[adjNode] != INF) {
                   setLengthNode.erase(setLengthNode.find(PII(dist[adjNode],adjNode)));
                }
                dist[adjNode] = length_to_adjnode + dist[cityOne];
                data.first = dist[adjNode];
                data.second = cityOne;
                distWAy[adjNode] = data;
                setLengthNode.insert(PII(dist[adjNode], adjNode));
            }
        }
    }
    PII temp = distWAy[cityTwo];
    pointArray.push_back(cityTwo);
    while (temp.second != 0 && temp.first != 0) {
        pointArray.push_back(temp.second);
        temp = distWAy[temp.second];
    }

    std::cout <<"\n" << pointArray.size();
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
    std::cout << "\ncityOne(" << cityOne << ") -> cityTwo(" << cityTwo << ") : " << dist[cityTwo] << " km" <<std::endl;
    std:: cout << "\t\tthe shortest road\n\t\t";
    std::cout << cityOne;
    for (int k = pointArray.size() - 1; k >= 0; --k) {
        std::cout <<"->" << pointArray[k];
    }
}