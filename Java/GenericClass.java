import java.util.ArrayList;
import java.util.Scanner;

class Stack<T> {
    int top, max;
    ArrayList<T> st;

    Stack(int n) {
        this.st = new ArrayList<T>(n);
        top = -1;
        max = n;
    }

    boolean isFull() {
        return top == max - 1;
    }

    boolean isEmpty() {
        return top == -1;
    }

    void push(T item) {
      if(isFull()){
          System.out.println("Is Full");
      }else{
          top++;
          st.add(item);
      }
    }

    void pop() {
        if (isEmpty()) {
            System.out.println("Stack is Empty");
        } else {
            T item = st.get(top);
            st.remove(top);
            top--;
            System.out.println(item + " Deleted");
        }
    }

    void display() {
        if (isEmpty()) {
            System.out.println("Stack is Empty");
        } else {
            for (int i = 0; i <= top; i++) {
                System.out.print(st.get(i) + "\t");
            }
        }
    }
}

class GenericClass  {
    public static void main(String[] args) {
        int ch, n;
        Scanner sc = new Scanner(System.in);
        Stack<Integer> s = new Stack<Integer>(5);
        Stack<String> s1 = new Stack<String>(5);
        Stack<Float> s2  = new Stack<Float>(5);
        s.push(4);
        s.push(22);
        s.push(55);
        System.out.println("Integer Stack");
        s.display();
        s1.push("Hello");
        s1.push("Java");
        s1.push("Lab");
        System.out.println("\nString Stack");
        s1.display();
        s2.push(3.23f);
        s2.push(4.24f);
        s2.push(5.22f);
        System.out.println("\nFloat Stack");
        s2.display();
        

    }

}
