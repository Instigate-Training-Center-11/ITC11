#include "BellmanFord.h"

enum city {Seattle,SanFrancisco,Denver,LasVegas,LosAngeles,Phoenix,Miami};


int main() {

    Graph graphcity(7);

    graphcity.AddEdge(Seattle,Denver);
    graphcity.AddEdgeWeight(Seattle,Denver,3000);
    graphcity.AddEdge(Seattle,Phoenix);
    graphcity.AddEdgeWeight(Seattle,Phoenix,2500);
    graphcity.AddEdge(SanFrancisco,LasVegas);
    graphcity.AddEdgeWeight(SanFrancisco,LasVegas,1900);
    graphcity.AddEdge(SanFrancisco,Miami);
    graphcity.AddEdgeWeight(SanFrancisco,Miami,5000);
    graphcity.AddEdge(Denver,LosAngeles);
    graphcity.AddEdgeWeight(Denver,LosAngeles,2000);
    graphcity.AddEdge(LasVegas,Phoenix);
    graphcity.AddEdgeWeight(LasVegas,Phoenix,1200);
    graphcity.AddEdge(Phoenix,Denver);
    graphcity.AddEdgeWeight(Phoenix,Denver,-3000);
    graphcity.AddEdge(Phoenix,LosAngeles);
    graphcity.AddEdgeWeight(Phoenix,LosAngeles,900);
    graphcity.AddEdge(Miami,Seattle);
    graphcity.AddEdgeWeight(Miami,Seattle,-2500);
    graphcity.AddEdge(Miami,Denver);
    graphcity.AddEdgeWeight(Miami,Denver,-1500);

    graphcity.BellmanFord(SanFrancisco);

    return 0;
}