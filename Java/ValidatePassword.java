import java.util.Scanner;

class ValidatePassword {
    static void isValid(String pswd) {
        if (pswd.length() < 8) {
            System.out.println("Invalid size");
        } else {
            char c;
            int numCount = 0;
            int charCount = 0;
            for (int i = 0; i < pswd.length(); i++) {
                c = pswd.charAt(i);
                if (isNum(c)) {
                    numCount++;
                } else if (isAlpha(c)) {
                    charCount++;
                } else {
                    System.out.println("Invalid Character");
                }
            }
            if (numCount >= 2 || charCount >= 2) {
                System.out.println("Valid password");
            } else {
                System.out.println("Invalid password");
            }
        }

    }

    static boolean isAlpha(char c) {
        c = Character.toUpperCase(c);
        return c >= 'A' || c <= 'Z';
    }

    static boolean isNum(char c) {
        return c >= '0' || c <= '9';
    }

    public static void main(String[] args) {
        String password;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a password to validate \n" +
                "(8 character length with minimum 2 numbers and 2 alphabets)");
        password = sc.next();
        isValid(password);

    }
}
