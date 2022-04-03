using namespace std;

#include "iostream"

int main() {
    int n, i, j, min, a[20];
    int temp;
    cout << "Enter the total number of elements";
    cin >> n;
    cout << "Enter the numbers";
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[min] > a[j]) {
                min = j;
            }
        }
        if (a[min] != a[i]) {
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
    for (i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
}