#include <iostream>
#include <stack>
#include <string>

/* Checks the correctness of the bracket mathematical expression */
bool checkStaples(std::string str);
/* Takes math operators and returns 1 if the argument is + or -, return 2  if the argument is * or / */
int changeSymbolAtDigit(char SymbolsOperations);
/* Function to perform arithmetic operations. return (a SymbolsOperations b) */
int calculate(int a, int b, char SymbolsOperations );
/* Sort necessity expressions calls functions changeSymbolAtDigit and calculate and the end returned
 * total amount of mathematical expression */
int parseString(std::string tokens);


int main() {
    std::string str = "( 2 + 2  * 8 ) / 4 - 5 * 10";
    if (checkStaples(str)) {
        std::cout << parseString(str) << "\n";
    }

    return 0;
}


int changeSymbolAtDigit(char SymbolsOperations ) {
    if (SymbolsOperations  == '+' || SymbolsOperations  == '-')
        return 1;
    if (SymbolsOperations  == '*' || SymbolsOperations  == '/')
        return 2;
    return 0;
}

int calculate(int a, int b, char SymbolsOperations) {
    switch (SymbolsOperations) {
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

int parseString(std::string tokens) {
    int i;
    /* a stack for storing integer values. */
    std::stack<int> valuesStack;
    /* a stack for storing operators. */
    std::stack<char> SymbolsOperationsStack;
    for (i = 0; i < tokens.length(); i++) {
        if (tokens[i] == ' ') {
            continue;
        } else if (tokens[i] == '(') {
            SymbolsOperationsStack.push(tokens[i]);
        } else if (isdigit(tokens[i])) {
            int val = 0;
            while (i < tokens.length() && isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }
            valuesStack.push(val);
        } else if (tokens[i] == ')') {
            while (!SymbolsOperationsStack.empty() && SymbolsOperationsStack.top() != '(') {
                int val2 = valuesStack.top();
                valuesStack.pop();

                int val1 = valuesStack.top();
                valuesStack.pop();

                char SymbolsOperations  = SymbolsOperationsStack.top();
                SymbolsOperationsStack.pop();

                valuesStack.push(calculate(val1, val2, SymbolsOperations ));
            }

            if (!SymbolsOperationsStack.empty()) {
                SymbolsOperationsStack.pop();
            }
        } else {
            /* While the top of 'SymbolsOperationsStack' has the same or greater
             * changeSymbolAtDigit to the current token, which is an operator.
             * Apply operator on top of 'SymbolsOperationsStack' to the top two
             * elements in valuesStack stack. */
            while (!SymbolsOperationsStack.empty() && changeSymbolAtDigit(SymbolsOperationsStack.top()) >= changeSymbolAtDigit(tokens[i])) {
                int val2 = valuesStack.top();
                valuesStack.pop();

                int val1 = valuesStack.top();
                valuesStack.pop();

                char SymbolsOperations  = SymbolsOperationsStack.top();
                SymbolsOperationsStack.pop();

                valuesStack.push(calculate(val1, val2, SymbolsOperations ));
            }
            SymbolsOperationsStack.push(tokens[i]);
        }
    }

    while (!SymbolsOperationsStack.empty()) {
        int val2 = valuesStack.top();
        valuesStack.pop();

        int val1 = valuesStack.top();
        valuesStack.pop();

        char SymbolsOperations  = SymbolsOperationsStack.top();
        SymbolsOperationsStack.pop();

        valuesStack.push(calculate(val1, val2, SymbolsOperations ));
    }

    return valuesStack.top();
}



bool checkStaples(std::string str) {
    int temp = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ')') {
            --temp;
            if (temp < 0) {
                std::cout << "Syntax error !!! at  index " << i << std::endl;
                return false;
            }
        }

        if (str[i] == '(') {
            ++temp;
        }

        ++i;
    }

    if (temp == 0) {
        return true;
    } else {
        std::cout << "There are unclosed staples\n";
        return false;
    }

}