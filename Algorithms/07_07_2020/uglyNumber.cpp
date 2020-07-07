#include <iostream>
#include <algorithm>

int min(int, int, int);
int uglyNumber(int);

int main() {
    int pos;
    std::cout << "Enter posinion of ugly number: ";
    std::cin >> pos;
    std::cout << "The " << pos << "-th ugly number is: " << uglyNumber(pos) << "\n";
}

int min(int x, int y, int z) {
    return std::min(std::min(x, y), z);
}

int uglyNumber(int pos) {
    int mul2 = 2;
    int mul3 = 3;
    int mul5 = 5;
    int index2 = 0;
    int index3 = 0;
    int index5 = 0;
    int uglyNumber[pos];
    int nextNumber = 1;

    uglyNumber[0] = 1;

    for (int i = 1; i < pos; ++i) {
        nextNumber = min(mul2, mul3, mul5);
        uglyNumber[i] = nextNumber;

        if (nextNumber == mul2) {
            ++index2;
            mul2 = uglyNumber[index2] * 2;
        }

        if (nextNumber == mul3) {
            ++index3;
            mul3 = uglyNumber[index3] * 3;
        }

        if (nextNumber == mul5) {
            ++index5;
            mul5 = uglyNumber[index5] * 5;
        }
    }

    return nextNumber;
}