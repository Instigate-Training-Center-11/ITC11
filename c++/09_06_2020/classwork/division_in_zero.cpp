#include <iostream>

int number(int a, int b) {
    if(0 == a) {
        throw 0;
    }
    return b / a;
}

int main() {
    int num0 = 3;
    int num1 = 15;

    try {
        std::cout << number(num0, num1);
    }
    catch(int ex) {
        std::cout << number(ex + 2,num1) << std::endl;
    }
    return 0;
}
