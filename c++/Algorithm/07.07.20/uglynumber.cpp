#include <iostream>

int min(int x, int y, int z) {
    if(x < y) {
        if(x < z)
            return x;
        else
            return z;
    }else {
        if(y < z)
            return y;
        else
            return z;
    }
}

int uglyNumber(int size) {
    int ugly[size];
    ugly[0] = 1;
    int count = 1;
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;

    while (count < size) {
        int val2 = ugly[i2] * 2;
        int val3 = ugly[i3] * 3;
        int val5 = ugly[i5] * 5;
        int val = min(val2, val3, val5);
        if (val == val2) i2++;
        if (val == val3) i3++;
        if (val == val5) i5++;
        ugly[count++] = val;
    }
    return ugly[size - 1];
}

int main() {
    int size;
    std::cout << "Enter index: ";
    std::cin >> size;
    std::cout << size << "th Ugly number is: " << uglyNumber(size) << std::endl;
}

