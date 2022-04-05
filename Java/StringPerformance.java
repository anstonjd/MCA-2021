import java.util.Scanner;

class StringPerformance {
    public static void main(String[] args) {

        String str1, str2;
        long startTime, total;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the string");
        str1 = sc.next();
        System.out.println("Enter the string to append");
        str2 = sc.next();
        startTime = System.currentTimeMillis();
        StringBuilder builder = new StringBuilder(str1);
        for (int i = 0; i < 100000; i++) {
            builder.append(str2);
        }
        total = System.currentTimeMillis() - startTime;
        System.out.println("Total time taken by string builder to append " + str2 + " 10000 times = " + total+" ms");
        startTime = System.currentTimeMillis();
        StringBuffer buffer = new StringBuffer(str1);
        for (int i = 0; i < 100000; i++) {
            buffer.append(str2);
        }
        total = System.currentTimeMillis() - startTime;
        System.out.println("Total time taken by string buffer to append " + str2 + " 10000 times = " + total+" ms");
    }

}
