#include <iostream>

/* checks input number is integer or not */
long type(int num) {
    while (std::cin.fail() || num < 1) {
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cout << "Enter a positive number: ";
        std::cin >> num;
    }
    return num;
}

/*Calculate the factorial using the recursive method*/
int recFact(int num) {
   if (num == 1) {
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

int main() {
    int num = 0;
    std::cout << "Enter a number: ";
    std::cin >> num;
    int input = type(num);
    std::cout <<"Using Recursion: ";
    std::cout << recFact(input) << std::endl;
    std::cout << "Using Iterative: ";
    std::cout << itrFact(input) << std::endl;
    return 0;
}
