/*Convert given infix expression Eg. a-b*c-d/e+f into postfix form using stack and 
show the operations step by step.*/

#include <iostream>
#include <stack>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '*' || op == '/') return 2; // higher precedence
    if (op == '+' || op == '-') return 1; // lower precedence
    return 0;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    stack<char> s;   // stack to store operators
    string postfix = ""; // result postfix expression

    for (char c : infix) {
        if (isalpha(c)) {
            // If character is an operand (a, b, c...), add to postfix
            postfix += c;
        } else {
            // If character is an operator
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                // Pop operators from stack if they have higher or equal precedence
                postfix += s.top();
                s.pop();
            }
            s.push(c); // Push current operator to stack
        }
    }

    // Pop any remaining operators from stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
