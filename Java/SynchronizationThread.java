class Table {
    void printTable(int n) {
        for (int i = 1; i <= 10; i++) {
            System.out.println(i + " * " + n + " = " + (i * n));
            try {
                Thread.sleep(10);
            } catch (Exception e) {
                System.out.println(e);
            }
        }
    }
}

class MyThread extends Thread {
    Table t;
    int n;

    MyThread(Table ta, int m) {
        t = ta;
        n = m;
    }

    public void run() {
        t.printTable(n);
    }
}

class SynchronizationThread {
    public static void main(String[] args) {
        Table t = new Table();
        MyThread t1 = new MyThread(t, 7);
        MyThread t2 = new MyThread(t, 3);
        t1.start();
        t2.start();
    }
}
