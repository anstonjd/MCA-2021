package p1;

import java.util.Scanner;

public class LMV extends Vehicle {
    int speedLimit, gearCount;

    public LMV() {
        speedLimit = 0;
        gearCount = 0;
    }

    public void input() {
        super.input();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the speed limit");
        speedLimit = sc.nextInt();
        System.out.println("Enter the gear count");
        gearCount = sc.nextInt();
    }

    public void display() {
        super.display();
        System.out.println("Speed limit= " + speedLimit);
        System.out.println("Gear count = " + gearCount);
    }
}
