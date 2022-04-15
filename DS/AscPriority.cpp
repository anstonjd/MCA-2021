#include "iostream"

using namespace std;

class priorityQ {
private:
    int q[25], n, r;
public:
    priorityQ(int m) {
        n = m;
        r = -1;
    }

    void insert() {
        int item;
        if (r >= n - 1) {
            cout << "Queue is full";
        } else {
            cout << "Enter the element";
            cin >> item;
            if (r == -1) {
                q[++r] = item;
            } else {
                int i = r;
                while (q[i] > item && i >= 0) {
                    q[i + 1] = q[i];
                    i--;
                }
                q[++i] = item;
                r++;
            }
        }
    }

    void deleteMin() {
        if (r == -1) {
            cout << "Queue is Empty \n";
        } else {
            cout << q[0] << "Deleted";
            for (int i = 1; i <= r ; i++) {
                q[i - 1] = q[i];
            }
            r--;
        }
    }


    void display() {
        if (r == -1) {
            cout << "Queue is Empty \n";
        } else {
            for (int i = 0; i <= r; i++) {
                cout << q[i] << "\t";
            }
            cout << "\n";
        }
    }
};

int main() {
    int n, ch;
    cout << "Enter the size of Queue";
    cin >> n;
    priorityQ pq(n);
    while (true) {
        cout << "Enter the choice : 1: Insert 2:Delete 3:Display 4:exit";
        cin >> ch;
        switch (ch) {
            case 1:
                pq.insert();
                break;
            case 2:
                pq.deleteMin();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Wrong choice";
        }
    }
}
