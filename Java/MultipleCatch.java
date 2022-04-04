import java.util.InputMismatchException;
import java.util.Scanner;

class MultipleCatch {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        try{
        System.out.println("Enter the Size of array");
        n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Array Created Successfully");
        }catch(NegativeArraySizeException na){
            System.out.println("Array size Cant be Negative");
        }catch(InputMismatchException im){
            System.out.println("Size needs to be in Int");
        }

    }
}
