import java.util.Scanner;

class IllegalMarksException extends Exception {
    public IllegalMarksException(String s) {
        super(s);
    }
}

class ResultFailException extends Exception {
    public ResultFailException(String s) {
        super(s);
    }
}

class Marks {
    int regno, m1, m2, m3;
    String name;

    void getData() throws IllegalMarksException {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the regno");
        regno = sc.nextInt();
        System.out.println("Enter the Name");
        name = sc.next();
        System.out.println("Enter the marks in 3 subjects");
        m1 = sc.nextInt();
        m2 = sc.nextInt();
        m3 = sc.nextInt();
        if (m1 < 0 || m2 < 0 || m3 < 0) {
            throw new IllegalMarksException("Negative Marks");
        }
    }

    void display() throws ResultFailException {
        System.out.println("Regno   = " + regno);
        System.out.println("Name    = " + name);
        System.out.println("Marks 1 = " + m1);
        System.out.println("Marks 2 = " + m2);
        System.out.println("Marks 3 = " + m3);
        if (m1 < 35 || m2 < 35 || m3 < 35) {
            throw new ResultFailException("Failed");
        }
        System.out.println("Total  = " + (m1 + m2 + m3));
    }
}

class UserDefinedException {
    public static void main(String[] args) {
        Marks m = new Marks();
        try {
            m.getData();
            m.display();
        } catch (IllegalMarksException ime) {
            System.out.println(ime);
        } catch (ResultFailException rfe) {
            System.out.println(rfe);
        }
    }
}