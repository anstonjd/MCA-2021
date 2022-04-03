#include "iostream"

using namespace std;
struct node {
    int data; //Data
    struct node *prev; //prev pointer
    struct node *next; //next pointer
};
typedef struct node *NODE;
NODE head;
class dll {
public:
    void insBeg() {
        NODE temp;
        temp = (NODE) malloc(sizeof(NODE));
        if (temp == NULL) {
            cout << "Overflow";
        } else {
            cout << "Enter the variable";
            cin >> temp->data;
            temp->prev = temp->next = NULL;
            if (head != NULL) {
                temp->next = head;
                head->prev = temp;
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
            cout << "Enter the variable";
            cin >> temp->data;
            temp->prev = temp->next = NULL;
            if (head == NULL) {
                head = temp;
            } else {
                NODE cur;
                cur = head;
                while (cur->next != NULL) {
                    cur = cur->next;
                }
                cur->next = temp;
                temp->prev = cur;
            }
        }
    }

    void delBeg() {
        if (head == NULL) {
            cout << "Empty";
        } else {
            if (head->next == NULL) {
                cout << head->data << " Deleted";
                free(head);
                head = NULL;
            } else {
                NODE cur;
                cur = head;
                head = head->next;
                head->prev = NULL;
                cout << cur->data << " Deleted";
                free(cur);
            }
        }
    }

    void delEnd() {
        if (head == NULL) {
            cout << "Empty";
        } else {
            if (head->next == NULL) {
                cout << head->data << " Deleted";
                free(head);
                head = NULL;
            } else {
                NODE cur, prev;
                cur = head;
                while (cur->next != NULL) {
                    prev = cur;
                    cur = cur->next;
                }
                prev->next = NULL;
                cout << cur->data << " Deleted";
                free(cur->next);

            }
        }
    }

    void display() {
        if (head == NULL) {
            cout << "Empty";
        } else {
            NODE cur;
            cur = head;
            while (cur) {
                cout << cur->data << "\t";
                cur = cur->next;
            }
        }
    }
};

int main() {
    dll l1;
    int ch;
    while (true) {
        cout << "\nEnter the choice: "
                "1: Insert Front \t2:Insert End \n"
                "3:Delete Front \t4:Delete End \t7:Display \t9:Exit :";
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