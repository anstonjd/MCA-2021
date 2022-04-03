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
    char str[30];
    int s1, s2;
    int c1, c2;
    cout << "Enter";
    cin >> str;
    cout << "Enter sub range";
    cin >> s1 >> s2;
    int i;
    for (i = 0; str[i]; i++);
    int count = i;
    if (s1 > s2) {
        cout << "Range invalid";
    } else if (s1 < count && s2 < count) {
        for (i = s1; i <= s2; i++) {
            cout << str[i];
        }
    } else {
        cout << "invalid range";
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