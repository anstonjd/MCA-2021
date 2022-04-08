package p1;

import java.util.Scanner;

public class Vehicle {
    private String name;
    private int wheelCount;

    public Vehicle() {
        name = "";
        wheelCount = 0;
    }

    void input() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the name of the vehicle");
        name = sc.next();
        System.out.println("Enter the wheel count");
        wheelCount = sc.nextInt();
    }

    void display() {
        System.out.println("Vehicle name = " + name);
        System.out.println("Wheel count = " + wheelCount);
    }
}
