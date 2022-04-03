//Priority Queue
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
            q[++r] = item;
        }
    }

    void del(bool flag) {
        if (r == -1) {
            cout << "Queue is Empty \n";
        } else if (r == 1) {
            r--;
        } else {
            int ele, loc, i;
            ele = q[0];
            loc = 0;
            for (i = 1; i < r; i++) {
                if (flag) {
                    if (ele > q[i]) {
                        ele = q[i];
                        loc = i;
                    }
                } else {
                    if (ele < q[i]) {
                        ele = q[i];
                        loc = i;
                    }
                }
            }
            for (i = loc; i < r ; ++i) {
                q[i] = q[i + 1];
            }
            cout<<ele<<" Removed\n";
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
            cout<<"\n";
        }
    }
};

int main() {
    int n, ch;
    cout << "Enter the size of stack";
    cin >> n;
    priorityQ pq(n);
    while (true) {
        cout << "Enter the choice : 1: Insert 2:Delete Min  3:Delete max 4:Display 5:exit";
        cin >> ch;
        switch (ch) {
            case 1:
                pq.insert();
                break;
            case 2:
                pq.del(true);
                break;
            case 3:
                pq.del(false);
                break;
            case 4:
                pq.display();
                break;
            case 5:
                exit(0);
            default:
                cout << "Wrong choice";
        }
    }
}
