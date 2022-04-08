class Class1 {
    int j = 10;

    void display() {
        class class2 {
            int i = 5;
            void display() {
                System.out.println("Inside Class 2");
                System.out.print(i++ + "\t");
                System.out.print(j++ + "\t");
            }
        }
        class2 c2 = new class2();
        c2.display();
        System.out.println("\nInside Class 1");
        System.out.print(c2.i + "\t");
        System.out.print(j + "\t");
    }
}

class InnerClass {
    public static void main(String[] args) {
        Class1 c1 = new Class1();
        c1.display();
    }
}
