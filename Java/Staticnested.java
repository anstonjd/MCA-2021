class Class1 {
    static int i = 10;

    static class Class2 {
        int j = 50;
        void display1() {
            System.out.println("Static class");
            System.out.println("variable from inner class " + j);
            System.out.println("variable from outer class " + i);
        }
    }
}

class Staticnested {
    public static void main(String[] args) {
        Class1.Class2 c1 = new Class1.Class2 ();
        c1.display1();
    }
}
