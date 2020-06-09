#include <iostream>

double divZ(int a, int b) {
    if(0 == b) {
        throw "Div in zero!!";
    }
    return a / b;
}

int main() {
    int a = 50;
    int b = 0;
    double c = 0;
    /*
    If you would like to see the function work without try catch; that you need
    to comment on the try catch block, open the line above.
    */
    //std::cout << divZ(a, b);
    try {
        c = divZ(a, b);
        std::cout << c << "\n";
    } catch(const char *e) {
        std::cerr << e << "\n";
    }
    return 0;
}