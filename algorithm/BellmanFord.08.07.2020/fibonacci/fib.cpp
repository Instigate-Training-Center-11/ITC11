
#include <iostream>
#include <vector>

long long int fibonacciReq(int n);
long long int fibonacci(int n,std::vector<long long int> fib);

int main() {
    std::vector<long long int> fib(2,0);
    int n = 0;
    fib[1] = 1;
    while (true) {
        std::cout << "Enter number position -> ";
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\nThat input is invalid.  Please try again.!!!!" << std::endl;
        } else {
            std::cin.ignore(32767, '\n');
            break;
        }
    }
    std:: cout << "Fibonacci number -> " << fibonacciReq(n) <<"\n";
    //std:: cout << "Fibonacci number -> " << fibonacci(n,fib) <<"\n";
    //std:: cout << "\nFibonacci number -> " << fibonacci(20,fib) <<"\n";
    //fib.clear();
    return 0;
}

long long int fibonacciReq(int n) {
    if((1 == n) || (0 == n)) {
      return n;
    }
    return(fibonacciReq(n - 1) + fibonacciReq(n - 2));
}




long long int fibonacci(int n,std::vector<long long int> fib) {

    if (n < fib.size()) {
        return fib[n];
    }

    long long int f1 = fib.size();
    long long int f2 = 0;
    long long int fibNumber = 0;
    for (int i = f1; i <= n; ++i) {
        f1 = fib[fib.size() - 2];
        f2 = fib[fib.size() - 1];
        fibNumber = f1 + f2;
        fib.push_back(fibNumber);
    }
    return fib[n];
}