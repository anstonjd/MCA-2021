import java.util.Scanner;
class Distance {
    double feet, inches;

    Distance() {
        feet = 0;
        inches = 0;
    }

    Distance(double feet, double inches) {
        this.feet = feet;
        this.inches = inches;
    }

    void display() {
        System.out.println("Feet = " + feet);
        System.out.println("Inches = " + inches);
    }

    Distance addDistance(Distance d1) {
        double i, f;
        f = feet + d1.feet;
        i = inches + d1.inches;
        if (i > 11) {
            i = i - 12;
            f++;
        }
        return new Distance(f, i);
    }
}

class DistanceArray {
    public static void main(String[] args) {
        Distance[] d = new Distance[10];
        Distance total = new Distance();
        Scanner sc = new Scanner(System.in);
        double feet,inches;
        for (int i = 0; i < 10; i++) {
            System.out.println("Enter Feet and inches for " +(i+1));
            feet = sc.nextDouble();
            inches = sc.nextDouble();
            d[i] = new Distance(feet,inches);
            total = total.addDistance(d[i]);
        }

        total.display();
        sc.close();
    }
}
