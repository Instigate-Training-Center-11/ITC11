#include <iostream>

int* testFoo(int&,int*);

int main() {
    int a = 10;
    int& b = a;
    int* c = &b;
    int k = 200;
    ++(*c);
    ++b;
    int* number = testFoo(a,c);

    return 0;
}

 int* testFoo(int& a,int* c) {
    static int number = 3;
    int* temp = new int (5);
    int f = 20;
    a += f;
    *c += f;
    delete temp;
    return &number;
}