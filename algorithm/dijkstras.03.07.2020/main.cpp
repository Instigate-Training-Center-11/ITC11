#include "dijkstras.h"

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

    DijkstrasShortestPath(Denver, Phoenix, graph);
    std::cout <<"\n";

    return 0;
}

