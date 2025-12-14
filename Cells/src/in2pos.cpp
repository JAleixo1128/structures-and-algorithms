#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

// Function to determine operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Helper to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to determine if an operator is right-associative
bool isRightAssociative(char op) {
    return op == '^'; // Exponentiation is right-associative
}

// Function to convert infix to postfix
string infixToPostfix(const string &expr) {
    stack<char> ops;        // Stack for operators and parentheses
    string result = "";     // Result string
    bool expectUnary = true; // Flag to detect unary minus

    for (size_t i = 0; i < expr.size(); i++) {
        char c = expr[i];

        if (isdigit(c) || (c == '-' && expectUnary)) { // Handle numbers or unary minus
            if (c == '-' && expectUnary) {
                result += c; // Add negative sign
                i++;         // Move to the next digit
            }
            result += expr[i];
            while (i + 1 < expr.size() && isdigit(expr[i + 1])) {
                result += expr[++i];
            }
            result += " ";
            expectUnary = false; // After a number, we don't expect unary anymore
        } else if (c == ' ') {
            continue; // Ignore spaces in the input
        } else if (c == '(') { // Left parenthesis
            ops.push(c);
            expectUnary = true; // Expect unary after '('
        } else if (c == ')') { // Right parenthesis
            while (!ops.empty() && ops.top() != '(') {
                result += ops.top();
                result += " ";
                ops.pop();
            }
            ops.pop(); // Remove the '('
            expectUnary = false; // '(' cannot precede unary minus
        } else if (isOperator(c)) { // If it's an operator
            while (!ops.empty() && ops.top() != '(' && 
                   (precedence(ops.top()) > precedence(c) || 
                    (precedence(ops.top()) == precedence(c) && !isRightAssociative(c)))) {
                result += ops.top();
                result += " ";
                ops.pop();
            }
            ops.push(c);
            expectUnary = true; // Expect unary after an operator
        }
    }

    // Pop any remaining operators
    while (!ops.empty()) {
        result += ops.top();
        result += " ";
        ops.pop();
    }

    // Remove the trailing space
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: ./in2pos <infix_expression>" << endl;
        return -1;
    }

    // Convert the infix expression to postfix
    string postfix = infixToPostfix(argv[1]);
    cout << postfix << endl;
    return 0;
}


