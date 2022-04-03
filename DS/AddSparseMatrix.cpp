#include "iostream"

using namespace std;


int main() {
    int a[20][3], b[20][3], c[20][3];
    int i, j, k, l, m, n, x, item;
    cout << "Enter the row and column size";
    cin >> m >> n;
    cout << "Enter the matrix 1" << endl;
    k = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> item;
            if (item != 0) {
                a[k][0] = i;
                a[k][1] = j;
                a[k][2] = item;
                k++;
            }
        }
    }

    l = 0;
    cout << "Enter the matrix 2" << endl;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> item;
            if (item != 0) {
                b[l][0] = i;
                b[l][1] = j;
                b[l][2] = item;
                l++;
            }
        }
    }


    i = j = x = 0;
    while (k > i && l > j) {
        if (a[i][0] > b[j][0] || (a[i][0] == b[j][0] && a[i][1] > b[j][1])) {
            c[x][0] = b[j][0];
            c[x][1] = b[j][1];
            c[x][2] = b[j][2];
            j++;
        } else if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[x][0] = a[i][0];
            c[x][1] = a[i][1];
            c[x][2] = a[i][2];
            i++;
        } else {
            c[x][0] = a[i][0];
            c[x][1] = a[i][1];
            c[x][2] = a[i][2] + b[j][2];
            i++;
            j++;
        }
        x++;
    }

    while (k > i) {
        c[x][0] = a[i][0];
        c[x][1] = a[i][1];
        c[x][2] = a[i][2];
        i++;
        x++;
    }

    while (l > j) {
        c[x][0] = b[j][0];
        c[x][1] = b[j][1];
        c[x][2] = b[j][2];
        j++;
        x++;
    }

    cout << "Addition" << endl;
    //Matrix Representation
    int e = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (c[e][0] == i && c[e][1] == j) {
                cout << c[e++][2] << " \t";
            } else {
                cout << "0 \t";
            }
        }
        cout << endl;
    }

    //3 Column Representation
    cout << endl;
    for (i = 0; i < x; i++) {
        cout << c[i][0] << "\t" << c[i][1] << "\t" << c[i][2] << endl;
    }

}