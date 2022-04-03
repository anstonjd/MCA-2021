//Stack
using namespace std;

#include <iostream>

class stack {
private:
    int st[20], top, n;

public:
    stack(int m) {
        top = -1;
        n = m; //max
    }

    void push() {
        int item;
        if (top == (n - 1)) {
            cout << "Stack is full";
            return;
        } else {
            cout << "Enter the element to push";
            cin >> item;
            top++;
            st[top] = item;
            return;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty";
            return;
        } else {
            cout << st[top] << "Pop Done";
            top--;
            return;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty";
            return;
        } else {
            for (int i = 0; i <= top; ++i) {
                cout << st[i] << "\t";
            }
        }
    }
};

int main() {
    int n, ch;
    cout << "Enter the size of stack";
    cin >> n;
    stack st1(n);
    while (true) {
        cout << "Enter the choice : 1: Push 2:Pop 3:Display 4:exit";
        cin >> ch;
        switch (ch) {
            case 1:
                st1.push();
                break;
            case 2:
                st1.pop();
                break;
            case 3:
                st1.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Wrong choice";
        }
    }
}
