#include <iostream>
#include <stack>

int setPrecedence (char);
int mathOperation(int, char, int);

int main()
{
    char expression[100];

    std::cout << "Insert math expression to solve: ";
    std::cin >> expression;

    /* stack for char math operators */
    std::stack<char> mathOperator;

    /* stack for integer numbers */
    std::stack<int> operand;

    int i = 0;

    while (expression[i] != '\0')
    {
        if (expression[i] == '(')
        {
            mathOperator.push('(');
        }
        else if (expression[i] == ')')
        {
            while (mathOperator.top() != '(')
            {
                int rightOperand = operand.top();
                operand.pop();

                int leftOperand = operand.top();
                operand.pop();

                int result = mathOperation(leftOperand, mathOperator.top(), rightOperand);

                operand.push(result);
                mathOperator.pop();
            }

            mathOperator.pop();
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            int precedence = setPrecedence(expression[i]);

            while (!mathOperator.empty() && setPrecedence(mathOperator.top()) >= precedence)
            {
                int rightOperand = operand.top();
                operand.pop();

                int leftOperand = operand.top();
                operand.pop();

                int result = mathOperation(leftOperand, mathOperator.top(), rightOperand);

                operand.push(result);
                mathOperator.pop();
            }
            mathOperator.push(expression[i]);
        }
        else
        {
            /* convert char to int and push it into operand stack*/
            operand.push(int(expression[i]) - '0');
        }
        i++;
    }
    while (!mathOperator.empty())
    {
        int rightOperand = operand.top();
        operand.pop();

        int leftOperand = operand.top();
        operand.pop();

        int result = mathOperation(leftOperand, mathOperator.top(), rightOperand);

        operand.push(result);
        mathOperator.pop();
    }
    //std::cout << "errrorr" << std::endl;
    std::cout <<"Result: " << operand.top() << std::endl;
    return 0;
}

int setPrecedence (char operation)
{
    switch (operation)
    {
        case '(':
            return 1;

        case '+':
        case '-':
            return 2;

        case '*':
        case '/':
            return 3;
    }
    return -1;
}

int mathOperation(int leftOperand, char operation, int rightOperand)
{
    switch (operation)
    {
        case '+':
            return leftOperand + rightOperand;

        case '-':
            return leftOperand - rightOperand;

        case '*':
            return leftOperand * rightOperand;

        case '/':
            if (rightOperand != 0)
            {
                return leftOperand / rightOperand;
            }
            else
            {
                std::cout << "Denominator can not be 0 ." << std::endl;
                break;
            }
            
        default:
            break;
    }
}