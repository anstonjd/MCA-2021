abstract class Shape {
    int length, breadth;

    Shape(int l, int b) {
        length = l;
        breadth = b;
    }

    abstract void area();
}

class Rectangle extends Shape {
    Rectangle(int l, int b) {
        super(l, b);
    }

    void area(){    
        int area=length*breadth;
        System.out.println("Area ="+ area);
    }
}
class Triangle extends Shape {
    Triangle(int l, int b) {
        super(l, b);
    }

    void area(){    
        int area=(length*breadth)/2;
        System.out.println("Area ="+ area);
    }
}

class DynamicDispatch {
    public static void main(String[] args) {
        Shape s;
        s =new Rectangle(4,5);
        s.area();
        s = new Triangle(8, 6);
        s.area();
    }
}
