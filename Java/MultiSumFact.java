class SumThread extends Thread {
    int n, sum;

    SumThread(int m, String name) {
        super(name);
        n = m;
        sum = 0;
    }

    public void run() {
        try {
            for (int i = 1; i <= n; i++) {
                sum = sum + i;
                Thread.sleep(50);
            }
            System.out.println(sum);
        } catch (Exception e) {
            System.out.println(e);
        }
    }

}

class FactThread extends Thread {
    int n, fact;

    FactThread(int m, String name) {
        super(name);
        n = m;
        fact = 1;
    }

    public void run() {
        try {
            for (int i = 1; i <= n; i++) {
                fact = fact * i;
                Thread.sleep(100);
            }
            System.out.println(fact);
        } catch (Exception e) {
            System.out.println(e);
        }
    }

}

class MultiSumFact {
    public static void main(String[] args) {
        SumThread st = new SumThread(100, "Thread 1");
        st.start();
        FactThread ft = new FactThread(5, "Thread 2");
        ft.start();
    }
}
