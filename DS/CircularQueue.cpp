#include "iostream"

using namespace std;

struct node {
    int data;
    struct node *next;
};
typedef struct node *NODE;
NODE head, last;
class cll {
public:
    void insBeg() {
        NODE temp;
        int item;
        temp = (NODE) malloc(sizeof(NODE));
        if (temp == NULL) {
            cout << "Overflow";
        } else {
            cout << "Enter the variable";
            cin >> item;
            temp->data = item;
            if (head == NULL) {
                head = temp;
                head->next = head;
                last = head;
            } else {
                last->next = temp;
                temp->next = head;
                head = temp;
            }
        }
    }

    void insEnd() {
        NODE temp;
        int item;
        temp = (NODE) malloc(sizeof(NODE));
        if (temp == NULL) {
            cout << "Overflow";
        } else {
            cout << "Enter the variable";
            cin >> item;
            temp->data = item;
            if (head == NULL) {
                head = temp;
                head->next = head;
                last = head;
            } else {
                temp->next = head;
                last->next = temp;
                last = temp;
            }
        }
    }

    void delBeg() {
        if (head == NULL) {
            cout << "Empty";
        } else {
            if (head->next == head) {
                cout << head->data << " Deleted";
                free(head);
                head = NULL;
            } else {
                NODE temp;
                temp = head;
                head = head->next;
                last->next = head;
                cout << temp->data << " Deleted";
                free(temp);
            }
        }
    }

    void delEnd() {
        if (head == NULL) {
            cout << "Empty";
        } else {
            if (head->next == head) {
                cout << head->data << " Deleted";
                free(head);
                head = NULL;
            } else {
                NODE cur;
                cur = head;
                while (cur->next != last) {
                    cur = cur->next;
                }
                cout << last->data << " Deleted";
                free(last);
                last = cur;
                last->next = head;
            }
        }
    }

    void display() {
        if (head == NULL) {
            cout << "\nnothing to print";
        } else {
            NODE cur;
            cur = head;
            while (cur->next != head) {
                cout << cur->data << "\t";
                cur = cur->next;
            }
            cout << cur->data << endl;
        }
    }
};

int main() {
    cll l1;
    int ch;
    while (true) {
        cout << "Enter the choice:";
        cout << "1: Insert Front 2:Insert End 3:Delete Beg 4:Delete end 7:Display 9:Exit :";
        cin >> ch;
        switch (ch) {
            case 1:
                l1.insBeg();
                break;
            case 2:
                l1.insEnd();
                break;
            case 3:
                l1.delBeg();
                break;
            case 4:
                l1.delEnd();
                break;
            case 7:
                l1.display();
                break;
            case 9:
                exit(0);
            default:
                cout << "Wrong choice";
        }
    }
}