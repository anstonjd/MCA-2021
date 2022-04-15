using namespace std;

#include "iostream"

struct node {
    int data;
    struct node *next; //Next pointer
};
typedef struct node *NODE;
NODE head;

class OrderedList {
public:
    void InsertData() {
        NODE temp = (NODE) malloc(sizeof(NODE));
        if (temp == NULL) {
            cout << "Overflow";
        } else {
            cout << "Enter the data";
            cin >> temp->data;
            temp->next = NULL;
            if (head == NULL) {
                head = temp;
            } else if (head->data >= temp->data) {
                temp->next = head;
                head = temp;
            } else {
                NODE prev;
                NODE cur = head;
                while (cur != NULL && cur->data <= temp->data) {
                    prev = cur;
                    cur = cur->next;
                }
                temp->next = prev->next;
                prev->next = temp;
            }
        }
    }

    void display() {
        if (head == NULL) {
            cout << "The list is empty";
        } else {
            NODE temp = head;
            while (temp != NULL) {
                cout << temp->data << "\t";
                temp = temp->next;
            }
        }
    }
};

int main() {
    OrderedList ol;
    int ch;
    while (true) {
        cout << "Enter the choice: "
                "1: Insert \t2: Display \t3: Exit :";
        cin >> ch;
        switch (ch) {
            case 1:
                ol.InsertData();
                break;
            case 2:
                ol.display();
                break;
            case 3:
                exit(0);
            default:
                cout << "Wrong choice";
        }
    }
}

