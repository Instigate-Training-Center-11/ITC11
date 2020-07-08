#include <iostream>

typedef unsigned long long int ul_int;

ul_int fib(int n);

int main() {
    std::cout << fib(11);

return 0;
}

ul_int fib(int index) {
    ul_int array[2][2] = {{1, 1},
                          {1, 0}};

    ul_int result[2] = {0, 1};

    ul_int temp_00 = 0;
    ul_int temp_01 = 0;
    ul_int temp_10 = 0;

    while (index) {
        /* Odd index */
        if (index & 1) {
            temp_10 = result[0];
            result[0] = result[0] * array[0][0] + result[1] * array[1][0];
            result[1] = temp_10 * array[0][1] + result[1] * array[1][1];
        }

        temp_00 = array[0][0]; temp_01 = array[0][1]; temp_10 = array[1][0];

        /* Multiply matrix by itself */
        array[0][0] = array[0][0] * array[0][0]  + array[0][1] * array[1][0];
        array[0][1] = temp_00 * array[0][1] + array[0][1] * array[1][1];
        array[1][0] = array[1][0] * temp_00 + array[1][1] * array[1][0];
        array[1][1] = temp_10 * temp_01 + array[1][1] * array[1][1];

        index /= 2;
    }

    return result[0];
}