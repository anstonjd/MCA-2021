#include "iostream"

using namespace std;

void insertion(int a[], int n) {
    int i,j,temp;
    for (i = 1; i < n; ++i) {
        temp = a[i];
        j = i-1;
        while (j>=0 && temp<a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
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
    insertion(a, n);
    for (i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
}