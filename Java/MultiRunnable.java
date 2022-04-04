class EvenThread implements Runnable {
    int n;
    Thread t;

    EvenThread(int m, String name) {
        t = new Thread(name);
        n = m;
    }

    public void run() {
        try {
            for (int i = 0; i <= n; i = i + 2) {
                System.out.println(t.getName() + "\t" + i);
                Thread.sleep(50);
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}

class OddThread implements Runnable {
    int n;
    Thread t;

    OddThread(int m, String name) {
        t = new Thread(name);
        n = m;
    }

    public void run() {
        try {
            for (int i = 1; i <= n; i = i + 2) {
                System.out.println(t.getName() + "\t" + i);
                Thread.sleep(50);
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}

class MultiRunnable {
    public static void main(String[] args) {
        EvenThread et = new EvenThread(50, "Even Thread");
        OddThread ot = new OddThread(40, "Odd Thread");
        Thread t1 = new Thread(et);
        Thread t2 = new Thread(ot);
        t1.start();
        t2.start();

    }
}
