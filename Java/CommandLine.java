class CommandLine {
    public static void main(String[] args) {
        int total = 0;
        int count = 0;
        for (int i = 0; i < args.length; i++) {
            try {
                total = total + Integer.parseInt(args[i]);
                count++;
            } catch (NumberFormatException e) {
                System.out.println(e);
            } 
        }
        System.out.println("The Total valid inputs are " + count);
        System.out.println("The sum of the valid inputs is " + total);
    }
}
