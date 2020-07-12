#include "ugly.h"

long long int uglyNumberDynamic(int n,std::vector<int> &data) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    if (data.size() > n) {
        return data[n];
    }
    int f2 = 1;
    int f3 = 1;
    int f5 = 1;

    data[1] = 1;
    for (int i = 2; i <= n; ++i) {
        long long int nextUglyNumber2 = dataUglyNumbers[f2] * 2;
        long long int nextUglyNumber3 = dataUglyNumbers[f3] * 3;
        long long int nextUglyNumber5 = dataUglyNumbers[f5] * 5;

        long long int thisNumber = min(nextUglyNumber2, min(nextUglyNumber3, nextUglyNumber5));
        data.push_back(thisNumber);
        if (thisNumber == nextUglyNumber2) {
            ++f2;
        }

        if (thisNumber == nextUglyNumber3) {
            ++f3;
        }

        if (thisNumber == nextUglyNumber5) {
            ++f5;
        }
    }

    return data[n];
}

long long int min(long long int num1, long long int num2) {
    if (num1 < num2) {
        return num1;
    }
    return num2;
}
