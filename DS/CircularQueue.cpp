//Circular Queue
using namespace std;

#include "iostream"

class cqu {
    int n, q[10], count, r, f;
public:
    cqu(int m) {
        n = m;
        count = 0;
        r = -1;
        f = 0;
    }

    void enqueue() {
        int item;
        if (count >= n) {
            cout << "Queue is full";
        } else {
            cout << "Enter the element";
            cin >> item;
            r = (r + 1) % n;
            q[r] = item;
            count++;
        }
    }

    void dequeue() {
        if (count <= 0) {
            cout << "Queue is empty";
        } else {
            f = (f + 1) % n;
            count--;
        }
    }

    void display() {
        if (count <= 0) {
            cout << "Queue is empty";
        } else {
            int f1 = f;
            for (int i = 0; i < count; ++i) {
                cout << q[f1] << "\t";
                f1 = (f1 + 1) % n;
            }
        }
    }
};

int main() {
    int ch, n;
    cout << "Enter the total size";
    cin >> n;
    cqu cq(n);
    while (true) {
        cout << "Enter the choice";
        cout << "1:Enqueue\n2:Dequeue\n3:Display\n4:Exit\n";
        cin >> ch;
        switch (ch) {
            case 1:
                cq.enqueue();
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Wrong choice";
        }
    }
}