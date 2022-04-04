import java.util.Scanner;

interface Stack {
    void push(int item);

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

    boolean isFull() {
        return top == (max - 1);
    }

    public void push(int item) {
        if (isFull()) {
            System.out.println("Stack is full");
        } else {
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

    public void push(int item) {
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
        Fstack f = new Fstack(3);
        Dstack d = new Dstack();
        int ch, ch2, item;
        Scanner sc = new Scanner(System.in);
        outer: while (true) {
            System.out.println("Enter your choice 1.Fstack 2.Dstack 3.Exit:");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    while (true) {
                        System.out.println("Enter your choice 1.push 2.pop 3.display 4.Exit:");
                        ch2 = sc.nextInt();
                        switch (ch2) {
                            case 1:
                                if (f.isFull()) {
                                    System.out.println("Stack is full");
                                } else {
                                    System.out.println("Enter the Element:");
                                    item = sc.nextInt();
                                    f.push(item);
                                }
                                break;
                            case 2:
                                f.pop();
                                break;
                            case 3:
                                f.display();
                                break;
                            case 4:
                                continue outer;
                            default:
                                System.out.println("\nwrong choice\n");
                        }
                    }
                case 2:
                    while (true) {
                        System.out.println("Enter your choice 1.push 2.pop 3.display 4.Exit:");
                        ch2 = sc.nextInt();
                        switch (ch2) {
                            case 1:
                                System.out.println("Enter the Element:");
                                item = sc.nextInt();
                                d.push(item);
                                break;
                            case 2:
                                d.pop();
                                break;
                            case 3:
                                d.display();
                                break;
                            case 4:
                                continue outer;
                            default:
                                System.out.println("\nwrong choice\n");
                        }
                    }
                case 3:
                    sc.close();
                    System.exit(0);
            }
        }
    }
}