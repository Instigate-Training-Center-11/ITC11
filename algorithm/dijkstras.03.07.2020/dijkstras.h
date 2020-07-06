#ifndef _DIJKSTAS_H_
#define _DIJKSTAS_H_
#include<iostream>
#include<vector>
#include<set>

enum city {Seattle,SanFrancisco,Denver,LasVegas,LosAngeles,Phoenix};

typedef std::pair<int,unsigned long long> PII;
typedef std::vector<PII> VECTORPAIR;
typedef std::vector<VECTORPAIR> VVPAIR;

void DijkstrasShortestPath (int cityOne,int cityTwo, VVPAIR& graph);

#endif