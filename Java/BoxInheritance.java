class Box {
    int height, length, breadth;

    Box() {
        height = 0;
        length = 0;
        breadth = 0;
    }

    Box(int height, int length, int breadth) {
        this.height = height;
        this.length = length;
        this.breadth = breadth;
    }

    void display() {
        System.out.println("Height = " + height);
        System.out.println("Length = " + length);
        System.out.println("Breadth = " + breadth);
    }
}

class BoxWeight extends Box {
    int weight;

    BoxWeight() {
        weight = 0;
    }

    BoxWeight(int height, int length, int breadth, int weight) {
        super(height, length, breadth);
        this.weight = weight;
    }

    void display() {
        super.display();
        System.out.println("Weight = " + weight);
    }
}

class BoxShipment extends BoxWeight {
    int cost;

    BoxShipment() {
        weight = 0;
    }

    BoxShipment(int height, int length, int breadth, int weight, int cost) {
        super(height, length, breadth, weight);
        this.cost = cost;
    }

    void display() {
        super.display();
        System.out.println("Cost = " + cost);
    }
}

class BoxInheritance {
    public static void main(String[] args) {
        BoxShipment bx = new BoxShipment(4, 5, 6, 500, 30);
        bx.display();
    }
}
