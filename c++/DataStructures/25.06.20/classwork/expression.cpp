#include <iostream>
#include <stack>
#include <cmath>

int precedence (char ch) {
    switch (ch) {
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        case '^':
            return 4;
    }
    return -1;
}

int operation(char ch, int lVal, int rVal) {
    switch (ch) {
        case '+':
            return lVal + rVal;
        case '-':
            return lVal - rVal;
        case '*':
            return lVal * rVal;
        case '/':
            if (rVal != 0) {
                return lVal / rVal;
            }
        case '^':
            return pow(lVal, rVal);
    }
    return -1;
}

int main() {
    char str[50];
    int l = sizeof(str)/sizeof(char);
    int k = 0;
    std::cout << "Enter expression: ";
    std::cin.getline(str,20);
    std::stack<char> op;
    std::stack<int> opVal;
    std::cout <<"Expression: " << str << std::endl;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '(') {
            op.push('(');
        } else if (str[i] == ')') {
            while (op.top() != '(') {
                int rVal = opVal.top();
                opVal.pop();
                int lVal = opVal.top();
                opVal.pop();
                int result = operation(op.top(), lVal, rVal);
                opVal.push(result);
                op.pop();
            }
            op.pop();
        } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){
            int pC = precedence(str[i]);
            while (!op.empty() && precedence(op.top()) >= pC){
                int rVal = opVal.top();
                opVal.pop();
                int lVal = opVal.top();
                opVal.pop();
                int result = operation(op.top(), lVal, rVal);
                opVal.push(result);
                op.pop();
            }
            op.push(str[i]);
        } else {
            opVal.push(int(str[i])- 48);
        }
        i++;
    }
    while (!op.empty()) {
        int rVal = opVal.top();
        opVal.pop();
        int lVal = opVal.top();
        opVal.pop();
        int result = operation(op.top(), lVal, rVal);
        opVal.push(result);
        op.pop();
    }
    std::cout <<"Result: " << opVal.top() << std::endl;
    return 0;
}

