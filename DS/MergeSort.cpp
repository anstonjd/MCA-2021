using namespace std;

#include "iostream"

void combine(int a[], int low, int mid, int high) {
    int temp[20];
    int k = low;
    int i = low;
    int j = mid + 1;
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= high) {
        temp[k++] = a[j++];
    }
    for (int p = low; p < k; p++) {
        a[p] = temp[p];
    }
}

void mergeSort(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        combine(a, low, mid, high);
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
    mergeSort(a, 0, n - 1);
    for (i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
}