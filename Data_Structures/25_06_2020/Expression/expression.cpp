#include <iostream>
#include <stack>
#include <string>

bool valid(std::string expr) {
    int res = 0;
    for (int i = 0; i < expr.length(); ++i) {
        if (expr[i] == '(') {
            ++res;
        } else if (expr[i] == ')') {
            --res;
        }
    }

    if (res == 0) {
        return true;
    } else {
        return false;
    }
}

int choose(int value1, int value2, char operand) {
    switch(operand) {
        case '+':
            return value1 + value2;
        case '-':
            return value1 - value2;
        case '*':
            return value1 * value2;
        case '/':
            return value1 / value2;
    }
}

int priority(char operand) {
    if(operand == '+' || operand == '-') {
        return 1;
    }
    if(operand == '*' || operand == '/') {
        return 2;
    }
    return 0;
}

int expression(std::string expr) {
    int i = 0;
    std::stack <int> numbers;
    std::stack <char> operands;

    for(i = 0; i < expr.length(); i++) {
        if(expr[i] == ' ') {
            continue;
        } else if(expr[i] == '(') {
            operands.push(expr[i]);
        } else if(isdigit(expr[i])) {
            int value = 0;
            while(i < expr.length() && isdigit(expr[i])) {
                value = (value * 10) + (expr[i] - '0');
                ++i;
            }
 
            numbers.push(value);
        } else if(expr[i] == ')') {
            while(!operands.empty() && operands.top() != '(') {
                int value1 = 0;
                int value2 = 0;
                char operand = '\0';

                value2 = numbers.top();
                numbers.pop();
                value1 = numbers.top();
                numbers.pop();
                operand = operands.top(); 
                operands.pop();
                numbers.push(choose(value1, value2, operand));
            }

            if(!operands.empty()) {
                operands.pop();
            }
        } else {
            while(!operands.empty() && priority(operands.top()) >= priority(expr[i])) {
                int value1 = 0;
                int value2 = 0;
                char operand = '\0';

                value2 = numbers.top();
                numbers.pop();
                value1 = numbers.top();
                numbers.pop();
                operand = operands.top();
                operands.pop();
                numbers.push(choose(value1, value2, operand));
            }

            operands.push(expr[i]);
        }
    }

    while(!operands.empty()) {
        int value1 = 0;
        int value2 = 0;
        char operand = '\0';

        value2 = numbers.top();
        numbers.pop();
        value1 = numbers.top();
        numbers.pop();
        operand = operands.top();
        operands.pop();
        numbers.push(choose(value1, value2, operand));
    }

    return numbers.top();
}

void print(std::string expr) {
    if(valid(expr)) {
        std::cout << expression(expr) << "\n";
    } else {
        std::cout << "The expression is not valid!" << "\n";
    }
}

int main() {
    std::string expr1 = "(4 + 5 * 2";
    std::string expr2 = "14 - ( 5 + 2 * 8 ) / 7";

    std::cout << "Result of the First expression: " << "\n";
    print(expr1);
    std::cout << "\n";

    std::cout << "Result of the Second expression: " << "\n";
    print(expr2);

    return 0;
}
