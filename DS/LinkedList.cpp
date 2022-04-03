//Linked list
using namespace std;

#include "iostream"

struct node {
    int data;
    struct node *next; //Next pointer
};
typedef struct node *NODE;
NODE head;

class ll {

public:
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

    void inputLoc() {
        NODE temp;
        temp = (NODE) malloc(sizeof(NODE));
        if (temp == NULL) {
            cout << "Overflow";
        } else {
            NODE cur;

            int loc;
            cout << "Enter the Variable";
            cin >> temp->data;
            temp->next = NULL;
            cout << "Enter the Location";
            cin >> loc;
            if (head == NULL && loc == 1) {
                head = temp;
            } else if (head == NULL) {
                cout << "Location does not exist";
            } else if (loc == 1) {
                temp->next = head;
                head = temp;
            } else if (loc > 1) {
                cur = head;
                for (int i = 1; i < loc - 1; i++) {
                    cur = cur->next;
                    if (cur == NULL) {
                        cout << "Location does not exist";
                        return;
                    }
                }
                temp->next = cur->next;
                cur->next = temp;
            } else {
                cout << "Error";
            }
        }
    }

    void delBeg() {
        if (head == NULL) {
            cout << "Empty";
        } else {
            NODE temp;
            temp = head;
            head = head->next;
            cout << temp->data << " Deleted";
            free(temp);
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
                free(cur);
            }

        }
    }

    void delLoc() {
        if (head == NULL) {
            cout << "Empty";
        } else {

            int loc;
            cout << "Enter the Location";
            cin >> loc;
            if (head->next == NULL && loc == 1) {
                cout << head->data << " Deleted";
                free(head);
                head = NULL;
            } else if (head == NULL || loc <= 0) {
                cout << "Location does not exist";
            } else if (loc == 1) {
                NODE temp = head;
                head = head->next;
                cout << temp->data << " :Deleted";
                free(temp);
            } else {
                NODE cur, prev;
                cur = head;
                for (int i = 1; i < loc; i++) {
                    prev = cur;
                    cur = cur->next;
                    if (cur == NULL) {
                        cout << "Location does not exist";
                        return;
                    }
                }
                prev->next = cur->next;
                cout << cur->data << " Deleted";
                free(cur);
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
    ll l1;
    int ch;
    while (true) {
        cout << "\nEnter the choice: "
                "1: Insert Front \t2:Insert End \t3:Insert Location \n"
                "4:Delete Front \t5:Delete End \t6:Delete Location\t7:Display \t9:Exit :";
        cin >> ch;
        switch (ch) {
            case 1:
                l1.insBeg();
                break;
            case 2:
                l1.insEnd();
                break;
            case 3:
                l1.inputLoc();
                break;
            case 4:
                l1.delBeg();
                break;
            case 5:
                l1.delEnd();
                break;
            case 6:
                l1.delLoc();
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
