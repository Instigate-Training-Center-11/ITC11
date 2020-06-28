#include <iostream>
#include "arrayStack.h"
using namespace std;

int main() {
    stack<int> s;
   // cout << s.isEmpty() << endl;
    for (int i = 0; i < 5; i++) {
        s.push(i*(i+1));
        cout << s.peek() << endl;
        }
    //     while (!s.isEmpty) {
    //        cout << s.pop() << " ";
    //        cout << endl;
    // }
    return 0;
}