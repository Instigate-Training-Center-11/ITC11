#include <iostream>
#include "Straser.cpp"
using namespace std;

int main()
{
    StrasAlg stras;
    cout << "Enter the Matrix 1 and matrix 2: " << endl;
    stras.inputing();
    stras.calculate();
    stras.display();
}
