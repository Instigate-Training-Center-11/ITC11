#include <iostream>
#include <string>
#include <stack>

using namespace std;

/* check the digits */
bool isDigit(char c) {
return (c >= '0' && c <= '9');
}

/* check the chars for operators */
bool isOp (char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}
/* determine the precedence or priority */
int getPrecedence (char c) {
    switch (c) {
        case '+':
        case '-':return 1;
        case '*':
        case '/': return 2;
        case '(':
        case ')': return 3;
        default: return -1;
    }
}
 int operate (int val1, int val2, char op) {
    if (op == '+') return val1 + val2;
    if (op == '-') return val1 - val2;
    if (op == '*') return val1 * val2;
    return val1 / val2;
}
 /* evalueate a string */
int evaluate (string s) {
    stack<int> vals;
    stack<char> ops;

    int val = 0;
    int pos = 0;

    while (pos < s.length()) {
        char spot = s[pos];  /* nish imastov */
        if (isDigit(spot)) {
            val = (val * 10) + (int) (spot - '0');
        }
        else if (isOp(spot)) {
           if (spot == '('){
           ops.push (spot);
           val = 0;
        }
        if (vals.empty) {  /* isEmpty */
            vals.push(val);
            ops.push(spot);
            val = 0;
        }
        else if (spot == ')') {
             vals.push(val);
             while (ops.peek() != '(') {
                spot = ops.pop();
                val = vals.pop();
                int prev = vals.pop();
                val = operate (prev, val, spot);
                vals.push(val);
             }
             ops.pop();
             vals.pop();
        }
        else {
            char prev = ops.peek();
            if (getPrecedence(spot) > getPrecedence(prev)){
                vals.push(val);
                ops.push(spot);
                val = 0;
            }
            else {
                int prevval = vals.pop();
                prevop = ops.pop();
                prevval = operate(prevval, val, prevop);
                vals.push(prevval);
                ops.push(spot);
                val = 0;
            }
        }
    }
        pos++;
    }
    while (!ops.empty()) {
        int prev = vals.pop();
        int spot = ops.pop();
        val = operate(prev, val, spot);
    }
    return val;
}

