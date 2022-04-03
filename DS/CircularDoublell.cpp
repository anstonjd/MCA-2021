#include "iostream"

using namespace std;

struct node {
    int data; //Data
    struct node *prev; //prev pointer
    struct node *next; //next pointer
};
typedef struct node *NODE;
NODE head, last;

class cdll {
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
                temp->prev = temp->next = temp;
                head = last = temp;
            } else {
                temp->prev = last;
                temp->next = head;
                head->prev = last->next = temp;
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
                head->prev = head->next = head;
                last = head;
            } else {
                temp->prev = last;
                last->next = temp;
                temp->next = head;
                head->prev = temp;
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
                head->prev = last;
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
            if (head->prev == head) {
                cout << head->data << " Deleted";
                free(head);
                head = NULL;
            } else {
                NODE temp;
                temp = last;
                last = last->prev;
                last->next = head;
                head->prev = last;
                cout << temp->data << " Deleted";
                free(temp);
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
    cdll l1;
    int ch;
    while (true) {
        cout << "\nEnter the choice:";
        cout << "1: Insert Front \t2:Insert End\t3:Delete Beg \t4:Delete end \t7:Display\t9:Exit :";
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