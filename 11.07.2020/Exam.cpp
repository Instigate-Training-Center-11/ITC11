#include <iostream>
#include <string>

void arrangeBrackets(int n, int open, int close, std::string str)
{
    if (close == n) {
        std::cout << str << std::endl;
        return;
    }    
    if (open < n) {
        arrangeBrackets(n, open + 1, close, str + "(");
    }
    if (open > close) {
        arrangeBrackets(n, open, close + 1, str + ")");
    }
}
