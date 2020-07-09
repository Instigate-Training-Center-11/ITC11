#include <iostream>
using namespace std;

#define MAX 32767

int minimumDist(int dist[], bool set[]) {
	int min = MAX;
	int index = 0;

	for(int i = 0; i < 3; ++i) {
		if(set[i] == false && dist[i] <= min) {
			min = dist[i];
			index = i;
		}
	}

	return index;
}

void dij(int graph[3][3], int src) {
	int dist[3];
	bool set[3];

	for(int i = 0; i < 3; i++) {
		dist[i] = MAX;
		set[i] = false;
	}

	dist[src] = 0;

	for(int i = 0; i < 3; ++i) {
		int m=minimumDist(dist, set);
		set[m] = true;
		for(int i = 0; i < 3; i++) {
			if(!set[i] && graph[m][i] && dist[m] != MAX && dist[m] + graph[m][i] < dist[i])
				dist[i] = dist[m] + graph[m][i];
		}
	}

	cout << "Distance from source" << endl;
	for(int i = 0; i < 3; ++i) {
		char str = 65 + i;
		cout << str << "\t" << dist[i] << endl;
	}
}

int main() {
	int graph[3][3] = {
		{0, 1, 2},
		{0, 0, 5},
		{0, 0, 0},
	};
	dij(graph,0);
	return 0;
}
