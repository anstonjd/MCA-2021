//Double ended queue
using namespace std;

#include "iostream"

class doubleQueue {
private:
    int dq[10], r, f, n;
public:
    doubleQueue(int m) {
        n = m;
        f = 0;
        r = -1;
    }

    bool isFull() {
        return f == 0 && r == (n - 1);
    }

    bool isEmpty() {
        return f > r || r == -1;
    }


    void insFront() {
        int item;
        if (isFull()) {
            cout << "Queue is full";
            return;
        }
        if (f == 0) {
            cout << "Cant do the operation";
        } else {
            cout << "Enter the element to insert";
            cin >> item;
            dq[--f] = item;
        }

    }

    void insRear() {
        int item;
        if (isFull()) {
            cout << "Queue is full";
            return;
        }
        if (r == (n - 1)) {
            cout << "Cant do the operation";
        } else {
            cout << "Enter the element to insert";
            cin >> item;
            dq[++r] = item;
        }
    }

    void delFront() {
        if (isEmpty()) {
            cout << "Queue is empty";
        } else {
            f++;
            cout << "Done";
        }

    }

    void delRear() {
        if (isEmpty()) {
            cout << "Queue is empty";
        } else {
            r--;
            cout << "Done";
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty";
        } else {
            for (int i = f; i <= r; i++) {
                cout << dq[i] << "\t";
            }
        }
    }
};

int main() {
    int n, ch;
    cout << "Enter the size of Queue";
    cin >> n;
    doubleQueue dqu(n);
    while (true) {
        cout << "\nEnter the choice : 1: Insert Front 2:Insert Rear 3:Delete front 4:Delete rear 5:Display 6:Exit";
        cin >> ch;
        switch (ch) {
            case 1:
                dqu.insFront();
                break;
            case 2:
                dqu.insRear();
                break;
            case 3:
                dqu.delFront();
                break;
            case 4:
                dqu.delRear();
                break;
            case 5:
                dqu.display();
                break;
            case 6:
                exit(0);
            default:
                cout << "Wrong choice";
        }
    }
}
