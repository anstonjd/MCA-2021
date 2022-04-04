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

class DistanceMain {
    public static void main(String[] args) {
        Distance d1 = new Distance(10, 11);
        Distance d2 = new Distance(56, 9);
        Distance d3 = new Distance();
        d3 = d1.addDistance(d2);
        d3.display();

    }
}
