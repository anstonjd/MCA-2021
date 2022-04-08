package p1;

import java.util.Scanner;

public class HMV extends Vehicle{
    int LoadCapacity, Sitting, Standing;
    String permit;

    public HMV() {
        LoadCapacity = 0;
        permit = "";
        Sitting = 0;
        Standing = 0;
    }

    public void input() {
        super.input();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the load capacity");
        LoadCapacity = sc.nextInt();
        System.out.println("Enter the Permit");
        permit = sc.next();
        System.out.println("Sitting capacity");
        Sitting = sc.nextInt();
        System.out.println("Standing capacity");
        Standing = sc.nextInt();
    }

    public void display() {
        super.display();
        System.out.println("load capacity = " + LoadCapacity);
        System.out.println("Permit = " + permit);
        System.out.println("Sitting = " + Sitting);
        System.out.println("Standing = " + Standing);
    }
}
