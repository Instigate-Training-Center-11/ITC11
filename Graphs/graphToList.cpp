#include <iostream>
#include <map>
#include <list>
using namespace std;

class ToList {
	map<int, list<int>> mp;
public:
	void inputDepend(int key, int *dep, int size) {
		list<int> ls;
		for(int i = 0; i < size; ++i) {
			ls.push_back(dep[i]);
		}
		mp[key] = ls;
	}

	void toString() {
		map<int, list<int>>::iterator itr;
		for (itr = mp.begin(); itr != mp.end(); ++itr) {
			cout << itr -> first;
			for (list<int>::iterator it = itr -> second.begin(); it != itr -> second.end(); ++it) {
				cout << " -> " << *it;
			}
			cout << endl;
		}
	}
};

/*
	0 --- 1 
	|     | \
	|     |  2
	|     | /
	4 --- 3 
*/

int main() {
	cout << "0 --- 1\n|     | \\\n|     |  2\n|     | /\n4 --- 3" << endl;
	ToList graph;
	int arr0[] = {1, 4};
	graph.inputDepend(0, arr0, 2);
	int arr1[] = {0, 2, 3};
	graph.inputDepend(1, arr1, 3);
	int arr2[] = {3, 1};
	graph.inputDepend(2, arr2, 2);
	int arr3[] = {1, 2, 4};
	graph.inputDepend(3, arr3, 3);
	int arr4[] = {0, 3};
	graph.toString();
	return 0;
}
