import java.util.Scanner;

interface Sports {
    double m4 = 7.5;

    void display();
}

class Student {
    int rno;
    String name, batch;

    Student() {
        rno = 0;
        name = "";
        batch = "";
    }

    void inputData() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the regno");
        rno = sc.nextInt();
        System.out.println("Enter the name");
        name = sc.next();
        System.out.println("Enter the batch");
        batch = sc.next();
    }

    void display() {
        System.out.println("Regno = " + rno);
        System.out.println("Name = " + name);
        System.out.println("Batch = " + batch);
    }
}

class Marks extends Student {
    int m1, m2, m3;

    Marks() {
        m1 = 0;
        m2 = 0;
        m3 = 0;
    }

    void inputData() {
        super.inputData();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Marks of 3 Subjects");
        m1 = sc.nextInt();
        m2 = sc.nextInt();
        m3 = sc.nextInt();

    }

    void display() {
        super.display();
        System.out.println("Marks 1 = " + m1);
        System.out.println("Marks 2 = " + m2);
        System.out.println("Marks 3 = " + m3);
    }
}

class Result extends Marks implements Sports {
    double total;

    Result() {
        total = 0;
    }

    void inputData() {
        super.inputData();
        total = m1 + m2 + m3 + m4;
    }

    public void display() {
        super.display();
        System.out.println("Total = " + total);
    }
}

class MultipleInheritanc {
    public static void main(String[] args) {
        Result r = new Result();
        r.inputData();
        r.display();
    }
}
