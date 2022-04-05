//Binary search with recursion
#include "iostream"

using namespace std;

int bSearch(int a[], int x, int l, int h) {
    int mid;
    if (l > h)
        return -1;
    mid = (h + l) / 2;
    if (x == a[mid])
        return mid;
    else if (a[mid] > x)
        return bSearch(a, x, l, mid - 1);
    else
        return bSearch(a, x, mid + 1, h);
}

int main() {
    int a[20],n;
    cout << "Enter the total number of elements";
    cin >> n;
    cout << "Enter the numbers";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter the searching element";
    int x;
    cin >> x;
    int loc = bSearch(a, x, 0, n);
    loc++;
    if (loc) {
        cout << "Found in " << loc;
    } else {
        cout << "Not found";
    }
}