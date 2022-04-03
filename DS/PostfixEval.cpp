using namespace std;

#include "iostream"
#include "cmath"

int compute(int op2, int op1, char sym) {
    int res;
    switch (sym) {
        case '+':
            res = op2 + op1;
            break;
        case '-' :
            res = op2 - op1;
            break;
        case '*' :
            res = op2 * op1;
            break;
        case '/' :
            res = op2 / op1;
            break;
        case '^':
            res = pow(op2, op1);
            break;
    }
    return res;
}

int main() {
    int st[10], i, op1, op2, top = -1,res,dig;
    char post[20],sym;
    cout << "Enter the string";
    cin >> post;
    for (i = 0; post[i]; i++) {
        sym = post[i];
        dig = sym-'0';
        if (dig>=0 && dig<=9) {
            st[++top] = dig;
        } else {
            op1 = st[top--];
            op2 = st[top--];
            res = compute(op2, op1, sym);
            st[++top] = res;
        }
    }
    cout << st[top];
}