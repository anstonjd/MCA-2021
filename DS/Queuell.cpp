//Queue
using namespace std;

#include <iostream>

struct node {
    int data;
    struct node *next;
};
typedef struct node *NODE;
NODE front, rear;

class queuell {
public:

    void Enqueue() {
        NODE temp;
        temp = (NODE) malloc(sizeof(NODE));
        if (temp == NULL) {
            cout << "Overflow";
        } else {
            NODE cur;
            cout << "Enter the variable";
            cin >> temp->data;
            temp->next = NULL;
            if (rear == NULL) {
                rear = front = temp;
            } else {
                rear->next= temp;
                rear = temp;
            }
        }
    }

    void Dequeue() {
        if (front == NULL) {
            cout << "Empty";
        } else {
            NODE temp;
            temp = front;
            front = front->next;
            cout << temp->data << " Deleted";
            free(temp);
        }
    }

    void display() {
        NODE temp;
        temp = front;
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
    queuell qull;
    while (true) {
        cout << "\nEnter the choice : 1: Enqueue 2:Dequeue 3:Display 4:exit";
        cin >> ch;
        switch (ch) {
            case 1:
                qull.Enqueue();
                break;
            case 2:
                qull.Dequeue();
                break;
            case 3:
                qull.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Wrong choice";
        }
    }
}
