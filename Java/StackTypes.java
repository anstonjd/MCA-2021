import java.util.Scanner;

interface Stack {
    void push();

    void pop();

    void display();
}

class Fstack implements Stack {
    int top, max, item;
    int st[];

    Fstack(int s) {
        max = s;
        top = -1;
        st = new int[max];
    }

    public void push() {
        if (top == max - 1) {
            System.out.println("Stack is full");
        } else {
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter the Element:");
            item = sc.nextInt();
            st[++top] = item;
        }
    }

    public void pop() {
        if (top == -1) {
            System.out.println("Empty");
        } else {
            item = st[top--];
            System.out.println(item + " Deleted");
        }
    }

    public void display() {
        if (top == -1) {
            System.out.println("Empty");
        } else {
            for (int i = 0; i <= top; i++) {
                System.out.print(st[i] + "\t");
            }
            System.out.println("");
        }
    }
}

class Dstack implements Stack {
    int max, top, item;
    int st[];

    Dstack() {
        top = -1;
        max = 5;
        st = new int[max];
    }

    public void push() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Element:");
        item = sc.nextInt();
        if (top == (max - 1)) {
            int temp[] = new int[max * 2];
            for (int i = 0; i <= top; i++) {
                temp[i] = st[i];
            }
            st = temp;
        }
        st[++top] = item;
    }

    public void pop() {
        if (top == -1) {
            System.out.println("Empty");
        } else {
            item = st[top--];
            System.out.println(item + " Deleted");
        }
    }

    public void display() {
        if (top == -1) {
            System.out.println("Empty");
        } else {
            for (int i = 0; i <= top; i++) {
                System.out.print(st[i] + "\t");
            }
            System.out.println();
        }

    }
}

class StackTypes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack s;
        s = new Fstack(0);
        int ch;
        outer: while (true) {
            System.out.println("Enter your choice 1.Fstack 2.Dstack 3.Exit:");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    s = new Fstack(5);
                    break;
                case 2:
                    s = new Dstack();
                    break;
                case 3:
                    System.exit(0);
                default:
                    System.out.println("wrong choice");
            }
            while (true) {
                System.out.println("Enter your choice 1.push 2.pop 3.display 4.Exit:");
                ch = sc.nextInt();
                switch (ch) {
                    case 1:
                        s.push();
                        break;
                    case 2:
                        s.pop();
                        break;
                    case 3:
                        s.display();
                        break;
                    case 4:
                        continue outer;
                    default:
                        System.out.println("\nwrong choice\n");
                }
            }
        }
    }
}
