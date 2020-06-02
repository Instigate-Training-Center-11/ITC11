#include <iostream>

/*Calculate the factorial using the recursive method*/           
int recFact(int num) {
   if (num == 1 || num == 0) {
        return 1;
    }
   return num * recFact(num - 1);
}

/*Calculate the factorial using the iterative method*/ 
int itrFact(int num) {
    int fact = 1;
    while (num > 0) {
        fact *= num;
        num--;
    } 
    return fact;
}

int main( )
{
    int num = 0;
    while (num < 1) {
        std::cout << "Enter a number: ";
        std::cin >> num;
    }
    std::cout <<"Using Recursion: ";
    std::cout << recFact(num) << std::endl;
    std::cout << "Using Iterative: "; 
    std::cout << itrFact(num) << std::endl;
    return 0;
}
