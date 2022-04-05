//Stack
using namespace std;

#include <iostream>

struct node {
    int data;
    struct node *next;
};
typedef struct node *NODE;
NODE head, top;

class stackll {
public:
    void push() {
        NODE temp;
        temp = (NODE) malloc(sizeof(NODE));
        if (temp == NULL) {
            cout << "Overflow";
        } else {
            NODE cur;
            cout << "Enter the variable";
            cin >> temp->data;
            temp->next = NULL;
            if (top == NULL) {
                top = head = temp;
            } else {
                top->next = temp;
                top = temp;
            }
        }
    }

    void pop() {
        if (top == NULL) {
            cout << "Empty";
        } else {
            if (head == top) {
                cout << top->data << " Deleted";
                free(top);
                top = NULL;
                head = NULL;
            } else {
                NODE cur;
                cur = head;
                while (cur->next != top) {
                    cur = cur->next;
                }
                cur->next = NULL;
                cout << top->data << " Deleted";
                free(top);
                top = cur;
            }
        }
    }

    void display() {
        NODE temp;
        temp = head;
        if (temp == NULL) {
            cout << "Empty";
        } else {
            while (temp != NULL) {
                cout << temp->data << "\t";
                temp = temp->next;
            }
        }
    }
};

int main() {
    int ch;
    stackll stll;
    while (true) {
        cout << "\nEnter the choice : 1: Push 2:Pop 3:Display 4:exit";
        cin >> ch;
        switch (ch) {
            case 1:
                stll.push();
                break;
            case 2:
                stll.pop();
                break;
            case 3:
                stll.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Wrong choice";
        }
    }
}
