// #Problem 1106: Parsing A Boolean Expression
// Date: 2024/10/20 Sunday

// Problem Statement:
// Given a string expression that represents a boolean expression, return the evaluation of that expression.
// The expression can be in one of the following forms:
// 't' for true, 'f' for false
// '!(subExpr)' for NOT
// '&(subExpr1, subExpr2, ..., subExprn)' for AND
// '|(subExpr1, subExpr2, ..., subExprn)' for OR

// Approach:
// 1. Use a recursive approach to evaluate the expression.
// 2. For each type of expression, handle it separately:
//    - For 't' and 'f', return the corresponding boolean value.
//    - For '!', recursively evaluate the inner expression and negate the result.
//    - For '&', return false if any subexpression is false, true otherwise.
//    - For '|', return true if any subexpression is true, false otherwise.
// 3. Use a helper function to parse subexpressions.

// Time Complexity: O(n), where n is the length of the expression.
// Space Complexity: O(n) for the recursive call stack.

#include <iostream>
#include <string>

class Solution {
public:
    bool parseBoolExpr(string expression) {
        return evaluate(expression, 0, expression.length() - 1);
    }

private:
    bool evaluate(const string& expr, int start, int end) {
        char op = expr[start];
        if (op == 't') return true;
        if (op == 'f') return false;
        
        if (op == '!') {
            return !evaluate(expr, start + 2, end - 1);
        }
        
        bool result = (op == '&'); // Initial result: true for AND, false for OR
        int i = start + 2; // Skip '(' after operator
        while (i < end) {
            int j = findCommaOrCloseParen(expr, i);
            bool subResult = evaluate(expr, i, j - 1);
            
            if (op == '&') {
                result = result && subResult;
                if (!result) return false; // Short-circuit for AND
            } else { // op == '|'
                result = result || subResult;
                if (result) return true; // Short-circuit for OR
            }
            
            i = j + 1;
        }
        
        return result;
    }
    
    int findCommaOrCloseParen(const string& expr, int start) {
        int count = 0;
        for (int i = start; i < expr.length(); i++) {
            if (expr[i] == '(') count++;
            if (expr[i] == ')') {
                if (count == 0) return i;
                count--;
            }
            if (count == 0 && expr[i] == ',') return i;
        }
        return expr.length() - 1; // Should never reach here with valid input
    }
};

int main() {
    Solution solution;

    // Example 1
    string expr1 = "&(|(f))";
    cout << "Expression: " << expr1 << "\nResult: " << (solution.parseBoolExpr(expr1) ? "true" : "false") << endl;

    // Example 2
    string expr2 = "|(f,f,f,t)";
    cout << "Expression: " << expr2 << "\nResult: " << (solution.parseBoolExpr(expr2) ? "true" : "false") << endl;

    // Example 3
    string expr3 = "!(&(f,t))";
    cout << "Expression: " << expr3 << "\nResult: " << (solution.parseBoolExpr(expr3) ? "true" : "false") << endl;

    // New test case
    string expr4 = "|(&(t,f,t),!(t))";
    cout << "Expression: " << expr4 << "\nResult: " << (solution.parseBoolExpr(expr4) ? "true" : "false") << endl;

    return 0;
}