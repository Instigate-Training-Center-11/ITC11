#include <iostream>

/*using dynamic algorithm*/
int fibonacci(int num) {
    int fib[num + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= num; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[num];
}

/*recursian method*/
int recFibonacci(int num, int *fibo) {
    if (num == 0) {
        return 0;
    }

    if (num == 1 || num == 2) {
        return 1;
    }

    if (fibo[num] != 0) {
        return fibo[num];
    } else {
        fibo[num] = (recFibonacci(num - 1, fibo) + recFibonacci(num - 2, fibo));
        return fibo[num];
    }
}

int main () {
    int num;
    int num1;
    std::cout << "Enter number: ";
    std::cin >> num;
    std::cout << num <<" th Fibonacci number: " << fibonacci(num) << std::endl;
    std::cout << "Enter number: ";
    std::cin >> num1;
    int *fibo = new int[num1 + 1];
    std::cout << num1 <<" th Fibonacci number: " << recFibonacci(num1, fibo) << std::endl;
    return 0;
}

