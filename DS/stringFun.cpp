using namespace std;

#include "iostream"

void concat() {
    char str1[30], str2[30];
    cout << "Enter the string 1 ";
    cin >> str1;
    cout << "Enter the string 2 ";
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
    cout << "Enter the string 1 ";
    cin >> str1;
    cout << "Enter the string 2 ";
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

void reverse() {
    char str[30];
    cout << "Enter the string ";
    cin >> str;
    int i;
    for (i = 0; str[i]; i++);
    int count = i;
    for (i = count - 1; i >= 0; i--) {
        cout << str[i];
    }
}

void subStr() {
    char str[30];
    int p1, p2;
    cout << "Enter the string ";
    cin >> str;
    cout << "Enter the Sub string range ";
    cin >> p1 >> p2;
    int i;
    for (i = 0; str[i]; i++);
    int count = i;
    if (p1 > p2) {
        cout << "Invalid Range";
    } else if (p1 < count && p2 < count) {
        for (i = p1; i < p2; i++) {
            cout << str[i];
        }
    } else {
        cout << "Invalid Range";
    }
}

void subStrPos() {
    char str[30], sub[30];
    int s1, s2;
    int c1, c2;
    cout << "Enter the String ";
    cin >> str;
    cout << "Enter the Sub string ";
    cin >> sub;
    int i, j;
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
        cout << "1:ConCat 2:Compare 3:Reverse 4:SubStr 5:SubStr Position 6:Exit ";
        cin >> ch;
        switch (ch) {
            case 1:
                concat();
                break;
            case 2:
                compare();
                break;
            case 3:
                reverse();
                break;
            case 4:
                subStr();
                break;
            case 5:
                subStrPos();
                break;
            case 6:
                exit(0);
            default:
                cout << "Wrong choice";
        }
    }
}