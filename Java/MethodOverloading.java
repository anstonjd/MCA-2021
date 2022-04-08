class Volume{
    int volume(int s){
        return s*s*s;
    }
    double volume(double r){
        return (4*3.143*r*r*r)/3;
    }
    double volume(double r,double h){
        return 3.143*r*r*h;
    }
}


class MethodOverloading {
    public static void main(String[] args) {
        Volume v = new Volume();
        System.out.println("Volume of Cube with side 5 = " + v.volume(5));
        System.out.println("Volume of sphere with radius 10.3 = " + v.volume(10.3));
        System.out.println("Volume of Cylinder with radius 5 and height  = " + v.volume(5,6));
    }    
}
