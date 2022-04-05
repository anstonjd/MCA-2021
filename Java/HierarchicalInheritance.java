import java.util.Scanner;

class Person {
    int Id, age;
    String name, college;

    Person() {
        Id = 0;
        age = 0;
        name = "";
        college = "";
    }

    void getData() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Id");
        Id = sc.nextInt();
        System.out.println("Enter the name");
        name = sc.next();
        System.out.println("Enter the college");
        college = sc.next();
        System.out.println("Enter the age");
        age = sc.nextInt();
    }

    void putData() {
        System.out.println("Id = " + Id);
        System.out.println("Name = " + name);
        System.out.println("College = " + college);
        System.out.println("Age = " + age);
    }
}

class Student extends Person {
    int courseNo;
    double gpa;

    Student() {
        courseNo = 0;
        gpa = 0;
    }

    void getData() {
        super.getData();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the course no");
        courseNo = sc.nextInt();
        System.out.println("Enter the gpa");
        gpa = sc.nextInt();
    }

    void putData() {
        super.putData();
        System.out.println("Course no = " + courseNo);
        System.out.println("Gpa = " + gpa);
    }
}

class Professor extends Person {
    String specialization;
    int noOfPublication;

    Professor() {
        specialization = "";
        noOfPublication = 0;
    }

    void getData() {
        super.getData();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the specialization");
        specialization = sc.next();
        System.out.println("Enter the No Of Publication");
        noOfPublication = sc.nextInt();
    }

    void putData() {
        super.putData();
        System.out.println("Specialization = " + specialization);
        System.out.println("No Of Publication = " + noOfPublication);
    }
}

class HierarchicalInheritance {
    public static void main(String[] args) {
        Person p[] = new Person[5];
        Scanner sc = new Scanner(System.in);
        int ch;
        System.out.println("Enter details of 5 person");
        for (int i = 0; i < 5; i++) {
            System.out.println("Enter the choice 1:Student 2:Professor");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    p[i] = new Student();
                    p[i].getData();
                    break;
                case 2:
                    p[i] = new Professor();
                    p[i].getData();
                    break;
                default:
                    System.out.println("Wrong choice");
            }
        }
        for (int i = 0; i < 5; i++) {
            p[i].putData();
            System.out.println("\n");
        }
    }
}
