class GenericMethods {
    public static <A> void printArray(A[] arr) {
        for (A elem : arr)
            System.out.print(elem + "\t");
    }

    public static void main(String[] args) {
        Integer[] integerArray = { 2, 4, 8, 16, 32 };
        Float[] floatArray = { 2.5f, 8.4f, 50.34f, 64.2f, 1.1f };
        Character[] charArray = { 'h', 'e', 'l', 'l', 'o' };
        System.out.println("Integer array ");
        printArray(integerArray);
        System.out.println("\nFloat array ");
        printArray(floatArray);
        System.out.println("\nChar array ");
        printArray(charArray);
    }
}
