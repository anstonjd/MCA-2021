//Infix to Post fix
using namespace std;

#include <iostream>
#include "string"
#include "stack"

int prec(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '/' || c == '*') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

void convert(char expr[]) {
    stack<char> st;
    string result;
    char c;
    int i;
    for (i = 0; expr[i]; i++) {
        c = expr[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            result += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && prec(c) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    cout << "Postfix expression is : " << result;
}

int main() {
    char expr[20];
    cout << "Enter the infix expression : ";
    cin >> expr;
    convert(expr);
}