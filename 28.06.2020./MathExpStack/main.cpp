#include <iostream>
#include "Calculator.cpp"

using namespace std;

int main() {
    cout << evaluate ("3 + 4 + 5") << endl; // 12
    cout << evaluate ("3 + 4 * 5") << endl; // 23
    cout << evaluate ("(3 + 4) * 5") << endl;  // 35
    return 0;
}