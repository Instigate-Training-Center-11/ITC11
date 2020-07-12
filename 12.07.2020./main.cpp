#include <iostream>
#include <string>
#include <vector>
#include "diffOfStr.cpp"

int main()
{
    std::string str1;
    std::string str2;

    std::cout << "Enter the firs std::string" << std::endl;
    std::cin >> str1;
    std::cout << "Enter the second std::string for compareing" << std::endl;
    std::cin >> str2;

    compare(str1, str2);
    display(vecForDiff);
    std::cout << std::endl;

    return 0;
}