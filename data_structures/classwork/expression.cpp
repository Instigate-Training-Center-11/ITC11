#include <stack>
#include <iostream>
#include <cstring>

std::string noSpace(std::string);
int priority(char);
int oper(int, int, char);
bool isValidOper(std::string);
bool isValidScope(std::string);
bool isValid(std::string);
void lastOperation(std::stack<int> &, std::stack <char> &);
void inStack(std::string, std::stack<int> &, std::stack <char> &);

int main() {
    std::stack <int> numbers;
    std::stack <char> symbols;
    char * myExpression;
    std::cout << "Please enter expression: ";
    std::cin.getline(myExpression, 100);

    if(isValid(noSpace(myExpression))) {
        inStack(myExpression, numbers, symbols);
        std::cout << myExpression << " = ";
        std::cout << numbers.top() << std::endl;
    } else {
        std::cout << "Expression is invalid!!!" << std::endl;
    }

    return 0;
}

int priority(char op) {
    if(op == '+' || op == '-') {
        return 1;
    }

    if(op == '*' || op == '/') {
        return 2;
    }

    if(op == '(') {
        return 3;
    }

    return 0;
}

int oper(int a, int b, char op) {
    switch(op){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
}

std::string noSpace(std::string str) {
    std::string newStr;
    for (int i = 0; i < str.length(); ++i) {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            continue;
        }

        newStr.push_back(str[i]);
    }

    return newStr;
}

bool isValidOper(std::string str) {
    if (str[str.length() - 1] == '-' || str[str.length() - 1] == '+'
     || str[str.length() - 1] == '/' || str[str.length() - 1] == '*') {
        return false;
    }

    if (str[0] == '-' || str[0] == '+'
     || str[0] == '/' || str[0] == '*') {
        return false;
    }

    for (int i = 0; i < str.length(); ++i) {
        if ((str[i] == '-' || str[i] == '+' || str[i] == '/' ||
             str[i] == '*') && (str[i + 1] == '-' || str[i + 1] == '+' ||
             str[i + 1] == '/' || str[i + 1] == '*')) {
                return false;
        }
    }

    return true;
}

bool isValidScope(std::string str) {
    int mark = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '(') {
            ++mark;
        } else if (str[i] == ')') {
            --mark;
        }
    }

    if (mark == 0) {
        return true;
    }

    return false;

}

bool isValid(std::string str) {
    if (isValidScope(str) && isValidOper(str)) {
        return true;
    }

    return false;
}

void lastOperation(std::stack<int> &values, std::stack <char> &ops) {
    int n = values.top();
    values.pop();
    int result = oper(values.top(), n, ops.top());
    ops.pop();
    values.pop();
    values.push(result);
}

void inStack(std::string expression, std::stack<int> &values, std::stack <char> &ops) {
    for (int i = 0; i < expression.length(); ++i) {
        expression = noSpace(expression);
       if (expression[i] == '(' || expression[i] == '+' || expression[i] == '-'
         || expression[i] == '*' || expression[i] == '/') {
            if (!ops.empty() && (priority(expression[i]) <= priority(ops.top())) ) {
                while (values.size() > 1 && priority(expression[i]) <= priority(ops.top()) && ops.top() != '(') {
                    int n = values.top();
                    values.pop();
                    int result = oper(values.top(), n, ops.top());
                    ops.pop();
                    values.pop();
                    values.push(result);
                }

                ops.push(expression[i]);
            } else {
                ops.push(expression[i]);
            }
        } else if(isdigit(expression[i])) {
            int digit = 0;
            while(i < expression.length() && isdigit(expression[i])) {
                digit = (digit * 10) + (expression[i] - '0');
                ++i;
            }

            --i;
            values.push(digit);
        } else if (expression[i] == ')') {
            while (ops.top() != '(') {
                lastOperation(values, ops);
            }

            ops.pop();
        }
    }

    while(!ops.empty()) {
        lastOperation(values, ops);
    }
}