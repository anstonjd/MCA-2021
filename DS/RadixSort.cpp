#include "iostream"

using namespace std;

int getMax(int a[], int n) {
    int max, i;
    max = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

void radixSort(int a[], int n) {
    int max, pos, i, k, b[20];

    max = getMax(a, n);
    k = 10;
    for (pos = 1; (max / pos) > 0; pos *= 10) {
        int count[10] = {0};
        for (i = 0; i < n; i++) {
            ++count[(a[i] / pos) % 10];
        }
        for (i = 1; i < k; i++) {
            count[i] = count[i] + count[i - 1];
        }
        for (i = n - 1; i >= 0; i--) {
            b[--count[(a[i] / pos) % 10]] = a[i];
        }
        for (i = 0; i < n; i++) {
            a[i] = b[i];
        }
    }
}

int main() {
    int n, i, a[20];
    cout << "Enter the total number of elements";
    cin >> n;
    cout << "Enter the numbers";
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    radixSort(a, n);
    for (i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
}