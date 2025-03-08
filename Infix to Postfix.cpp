#include <iostream>
#include <string>
using namespace std;

class stack {
public:
    int max;
    int top;
    char *equation;

    stack(int e) : max(e), top(-1) {
        equation = new char[e];
    }

    ~stack() {
        delete[] equation;
    }

    bool push(char op) {
        if (top >= (max - 1)) {
            cout << "stack overflow!" << endl;
            return false;
        } else {
            equation[++top] = op;
            cout << "Item pushed: " << op << endl;
            return true;
        }
    }

    char pop() {
        if (top < 0) {
            cout << "stack underflow!" << endl;
            return 0;
        } else {
            return equation[top--];
        }
    }

    bool isempty() {
        return (top < 0);
    }

    char peek() {
        if (isempty()) {
            cout << "stack is empty!" << endl;
            return 0;
        }
        return equation[top];
    }

    int precedence(char c) {
        if (c == '^') return 3;
        else if (c == '*' || c == '/') return 2;
        else if (c == '+' || c == '-') return 1;
        return -1;
    }

    string infixtopostfix(string eq) {
        string postfix = "";
        stack s(eq.length());

        for (int i = 0; i < eq.length(); i++) {
            char c = eq[i];

            if (isalnum(c)) {
                postfix += c;
            } else if (c == '(') {
                s.push(c);
            } else if (c == ')') {
                while (!s.isempty() && s.peek() != '(') {
                    postfix += s.pop();
                }
                s.pop();
            } else {
                while (!s.isempty() && precedence(c) <= precedence(s.peek())) {
                    postfix += s.pop();
                }
                s.push(c);
            }
        }

        while (!s.isempty()) {
            postfix += s.pop();
        }
        return postfix;
    }
};

int main() {
    stack s1(100);
    string equ = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Postfix: " << s1.infixtopostfix(equ) << endl;
    return 0;
}
