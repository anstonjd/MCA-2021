#include "iostream"

using namespace std;

int partition(int a[], int low, int high) {
    int pivot, i, j, temp;
    bool flag = true;
    pivot = a[low];
    i = low;
    j = high;
    while (flag) {
        do {
            i++;
        } while (a[i] < pivot);
        do {
            j--;
        } while (a[j] > pivot);
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            flag = false;
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
        }
    }
    return j;
}

void quickSort(int a[], int low, int high) {
    int j;
    if (low < high) {
        j = partition(a, low, high);
        quickSort(a, low, j);
        quickSort(a, j + 1, high);
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
    quickSort(a, 0, n);
    for (i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
}