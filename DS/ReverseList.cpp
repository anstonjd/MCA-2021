//Linked list
using namespace std;

#include "iostream"

struct node {
    int data;
    struct node *next; //Next pointer
};
typedef struct node *NODE;
NODE head;

class ReverseList {

public:

// Insert functions are same as Single linked list function


    void insBeg() {
        NODE temp;
        temp = (NODE) malloc(sizeof(NODE));
        if (temp == NULL) {
            cout << "Overflow";
        } else {
            cout << "Enter the variable";
            cin >> temp->data;
            temp->next = NULL;
            if (head != NULL) {
                temp->next = head;
            }
            head = temp;
        }
    }

    void insEnd() {
        NODE temp;
        temp = (NODE) malloc(sizeof(NODE));
        if (temp == NULL) {
            cout << "Overflow";
        } else {
            NODE cur;
            cout << "Enter the variable";
            cin >> temp->data;
            temp->next = NULL;
            if (head == NULL) {
                head = temp;
            } else {
                cur = head;
                while (cur->next != NULL) {
                    cur = cur->next;
                }
                cur->next = temp;
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

    void reverse() {
        if (head == NULL) {
            cout << "Empty";
        } else if (head->next == NULL) {
            cout << "Single element in list.. cant be reversed";
        } else {
            NODE cur = head;
            NODE prev = NULL, next = NULL;
            while (cur) {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            head = prev;
        }
    }
};

int main() {
    ReverseList r1;
    int ch;
    while (true) {
        cout << "\nEnter the choice: "
                "1: Insert Front \t2:Insert End \t3: Reverse List\t7:Display \t9:Exit :";
        cin >> ch;
        switch (ch) {
            case 1:
                r1.insBeg();
                break;
            case 2:
                r1.insEnd();
                break;
            case 3:
                r1.reverse();
                break;
            case 7:
                r1.display();
                break;
            case 9:
                exit(0);
            default:
                cout << "Wrong choice";
        }
    }
}
