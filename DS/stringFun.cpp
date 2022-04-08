using namespace std;

#include "iostream"

void count() {
    char str[30];
    cout << "Enter";
    cin >> str;
    int i;
    for (i = 0; str[i]; i++);
    cout << i;
}

void reverse() {
    char str[30];
    cout << "Enter";
    cin >> str;
    int i;
    for (i = 0; str[i]; i++);
    int count = i;
    for (i = count - 1; i >= 0; i--) {
        cout << str[i];
    }
}

void concat() {
    char str1[30], str2[30];
    cout << "Enter 1";
    cin >> str1;
    cout << "Enter 2";
    cin >> str2;
    int i;
    for (i = 0; str1[i]; i++);
    int count = i;
    for (i = 0; str2[i]; i++) {
        str1[count++] = str2[i];
    }
    str1[count] = '\0';
    cout << str1;
}

void compare() {
    char str1[30], str2[30];
    cout << "Enter 1";
    cin >> str1;
    cout << "Enter 2";
    cin >> str2;
    int i = 0;
    bool flag = true;
    while (str1[i] || str2[i]) {
        if (str1[i] != str2[i]) {
            flag = false;
            break;
        }
        i++;
    }
    if (flag) {
        cout << "Equal";
    } else {
        cout << "Not equal";
    }
}

void substr() {
    char str[30], sub[30];
    int s1, s2;
    int c1, c2;
    cout << "Enter the String";
    cin >> str;
    cout << "Enter the Sub string";
    cin >> sub;
    int i,j;
    for (i = 0; str[i]; i++);
    int count1 = i;
    for (i = 0; sub[i]; i++);
    int count2 = i;
    int x;
    if (count1 < count2) {
        cout << "Substring greater than Main string";
    } else {
        bool flag;
        for (i = 0; i < count1; i++) {
            int k = 0;
            flag = true;
            for (j = i; j < i + count2; j++) {
                if (str[j] != sub[k++]) {
                    flag = false;
                }
            }
            if (flag) {
                break;
            }
        }
        if (flag) {
            cout << i << " - " << j;
        } else {
            cout << "Not found";
        }
    }

}

int main() {
    int ch;
    while (true) {
        cout << "\n Enter the choice ";
        cout << "1:Count 2:Reverse 3:ConCat 4:Compare 5:SubStr 6:Exit ";
        cin >> ch;
        switch (ch) {
            case 1:
                count();
                break;
            case 2:
                reverse();
                break;
            case 3:
                concat();
                break;
            case 4:
                compare();
                break;
            case 5:
                substr();
                break;
            case 6:
                exit(0);
            default:
                cout << "Wrong choice";
        }
    }
}