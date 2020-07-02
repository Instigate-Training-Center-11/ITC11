#include <iostream>
#include <vector>
#include <list>
using namespace std;

/* Let's assign the number of peaks */
const int PEAKS = 7;

int main() {
    vector<list<int>> peaksList(PEAKS);

    /* Let's show the connections between the peaks.*/

    peaksList[1].push_back(5);
    peaksList[1].push_back(2);

    peaksList[2].push_back(5);
    peaksList[2].push_back(3);
    peaksList[2].push_back(1);

    peaksList[3].push_back(2);
    peaksList[3].push_back(4);

    peaksList[4].push_back(3);
    peaksList[4].push_back(5);
    peaksList[4].push_back(6);

    peaksList[5].push_back(4);
    peaksList[5].push_back(2);
    peaksList[5].push_back(1);

    peaksList[6].push_back(4);

    /* Now we need to print connections of graf using iterator */

    vector<list<int>>::iterator i;
    int num = 1;
    for (vector<list<int>>::iterator i = peaksList.begin() + 1; i != peaksList.end(); ++i) {
        cout << "vertices connected to node " << num << " are" << '\t';
        list<int> li = *i;
        for (list<int>::iterator iter = li.begin(); iter != li.end(); ++iter) {
            cout << *iter << '\t';
        }
        cout << endl;
        num++;
    }
    
}



