#include <iostream>
#include "Exam.cpp"

int main() {
    int n;
    std::cout << "How many pairs of brackets do you have? Enter the number: " << std::endl;
    std::cin >> n;
    arrangeBrackets(n, 0, 0, "");
    return 0;
}
