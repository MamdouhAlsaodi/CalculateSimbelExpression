#pragma once
#include <string>
#include <cctype>
#include <cmath>
#include "clsStack.h"
#include <stdexcept>
using namespace std;

template <typename T>
class clsExpressionEvaluator {
private:
    int _precedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/' || op == '%')
            return 2;
        if (op == '^')
            return 3;
        return 0;
    }

    T _applyOp(T a, T b, char op) {
        switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw runtime_error("Division by zero");
            return a / b;
        case '%':
            if (b == 0) throw runtime_error("Division by zero");
            return static_cast<int>(a) % static_cast<int>(b);
        case '^': return pow(a, b);
        default: throw runtime_error("Invalid operator");
        }
    }

    bool _isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
    }

public:
    T Evaluate(const string& expr) {
        clsStack<T> values;
        clsStack<char> ops;
        size_t i = 0;

        while (i < expr.length()) {
            if (isspace(expr[i])) { i++; continue; }

            if (isdigit(expr[i]) || expr[i] == '.') {
                string num;
                while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.'))
                    num += expr[i++];
                values.push(static_cast<T>(stod(num)));
                continue;
            }

            if (expr[i] == '(') {
                ops.push(expr[i]);
            }
            else if (expr[i] == ')') {
                while (!ops.isEmpty() && ops.top() != '(') {
                    if (values.size() < 2) throw runtime_error("Invalid expression");
                    T b = values.top(); values.pop();
                    T a = values.top(); values.pop();
                    char op = ops.top(); ops.pop();
                    values.push(_applyOp(a, b, op));
                }
                if (!ops.isEmpty()) ops.pop();
            }
            else if (_isOperator(expr[i])) {
                // دعم الرقم السالب بعد عامل أو ( أو بداية التعبير
                int j = i - 1;
                while (j >= 0 && isspace(expr[j])) j--;
                if (expr[i] == '-' && (i == 0 || expr[j] == '(' || _isOperator(expr[j]))) {
                    string num = "-";
                    i++;
                    while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.'))
                        num += expr[i++];
                    values.push(static_cast<T>(stod(num)));
                    continue;
                }

                while (!ops.isEmpty() &&
                    (_precedence(ops.top()) > _precedence(expr[i]) ||
                        (_precedence(ops.top()) == _precedence(expr[i]) && expr[i] != '^'))) {
                    if (values.size() < 2) throw runtime_error("Invalid expression");
                    T b = values.top(); values.pop();
                    T a = values.top(); values.pop();
                    char op = ops.top(); ops.pop();
                    values.push(_applyOp(a, b, op));
                }
                ops.push(expr[i]);
            }
            else {
                throw runtime_error(string("Invalid character: ") + expr[i]);
            }
            i++;
        }

        while (!ops.isEmpty()) {
            if (values.size() < 2) throw runtime_error("Invalid expression");
            T b = values.top(); values.pop();
            T a = values.top(); values.pop();
            char op = ops.top(); ops.pop();
            values.push(_applyOp(a, b, op));
        }

        if (values.isEmpty()) throw runtime_error("Empty expression");
        return values.top();
    }
};
