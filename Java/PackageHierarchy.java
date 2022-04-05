import java.util.Scanner;

import p1.*;

public class PackageHierarchy {
    public static void main(String[] args) {
        int ch;
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("Enter the choice 1:LMV 2:HMV 3:Exit");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    LMV l = new LMV();
                    l.input();
                    l.display();
                    break;
                case 2:
                    HMV h = new HMV();
                    h.input();
                    h.display();
                    break;
                case 3:
                    System.exit(0);
                default:
                    System.out.println("Wrong choice");
            }
        }

    }
}
