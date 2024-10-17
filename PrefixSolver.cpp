#include <iostream>
#include <stack>
#include <string>
using namespace std;
int evaluatePrefixExpression(string expression) {
    stack<int> stack;

    for (int i = expression.length() - 1; i >= 0; i--) {
        if (isdigit(expression[i])) {
            stack.push(expression[i] - '0');
        } else {
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            if (expression[i] == '+') {
                stack.push(operand1 + operand2);
            } else if (expression[i] == '-') {
                stack.push(operand1 - operand2);
            } else if (expression[i] == '*') {
                stack.push(operand1 * operand2);
            } else {
                stack.push(operand1 / operand2);
            }
        }
    }

    return stack.top();
}

int main() {
    string expression;
    cout << "Enter a prefix expression: ";
    cin >> expression;

    int result = evaluatePrefixExpression(expression);
    cout << "Result: " << result << endl;

    return 0;
}
