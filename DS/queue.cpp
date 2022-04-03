//Queue
using namespace std;

#include <iostream>


class queue {
private:
    int q[20],f, r,n;

public:
    queue(int m) {
        n=m;
        f = 0;
        r = -1;
    }

    void Enqueue() {
        int item;
        if (r >= (n-1)) {
            cout << "Queue is full";
        } else {
            cout << "Enter the element to add to queue";
            cin >> item;
            q[++r] = item;
        }
    }

    void Dequeue() {
        if (f > r) {
            cout << "Queue is empty";
        } else {
            cout << q[f++] << "Pop Done";
        }
    }

    void display() {
        if (f > r) {
            cout << "Queue is empty";
        } else {
            for (int i = f; i <= r; ++i) {
                cout << q[i] << "\t";
            }
        }
    }
};

int main() {
    int n,ch;
    cout << "Enter the size of queue";
    cin >> n;
    queue qu(n);
    while (true) {
        cout << "Enter the choice : 1: Enqueue 2:Dequeue 3:Display 4:exit";
        cin >> ch;
        switch (ch) {
            case 1:
                qu.Enqueue();
                break;
            case 2:
                qu.Dequeue();
                break;
            case 3:
                qu.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Wrong choice";
        }
    }
}
