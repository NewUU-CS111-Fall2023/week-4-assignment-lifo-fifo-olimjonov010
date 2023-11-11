/*
 * Author: Olimjonov Odiljon 
 * Date: 11.11.2023
 * Name: Olimjonov Odiljon
 */
//5//
#include <bits/stdc++.h> 
using namespace std; 
  
void towerOfHanoi(int n, char from_rod, char to_rod, 
                  char aux_rod) 
{ 
    if (n == 0) { 
        return; 
    } 
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod); 
    cout << "Move disk " << n << " from rod " << from_rod 
         << " to rod " << to_rod << endl; 
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); 
} 
  
// Driver code 
int main() 
{ 
    int N = 3; 
  
    // A, B and C are names of rods 
    towerOfHanoi(N, 'A', 'C', 'B'); 
    return 0; 
}
//3//
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfixExpression(const string &expression) {
    stack<int> operands;

    for (char c : expression) {
        if (isdigit(c)) {
            // If it's a digit, push it onto the stack
            operands.push(c - '0');
        } else if (c == '+'  c == '-'  c == '*') {
            // If it's an operator, pop the top two operands, apply the operator, and push the result back
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            int result;
            if (c == '+') {
                result = operand1 + operand2;
            } else if (c == '-') {
                result = operand1 - operand2;
            } else if (c == '*') {
                result = operand1 * operand2;
            }

            operands.push(result);
        }
    }

    // The final result will be at the top of the stack
    return operands.top();
}

int main() {
    string expression;
    cin >> expression;

    int result = evaluatePostfixExpression(expression);
    cout << "Result: " << result << endl;

    return 0;
}
