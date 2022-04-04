import java.io.*;

class FileStream {
    public static void main(String[] args) {
        int sample = 5;
        String str1 = "Hello this is a  string";
        try {
            FileOutputStream file = new FileOutputStream("text.txt");
            ObjectOutputStream oos = new ObjectOutputStream(file);
            oos.writeObject(str1);
            oos.writeInt(sample);
            oos.close();
            FileInputStream fis = new FileInputStream("text.txt");
            ObjectInputStream ois = new ObjectInputStream(fis);
            System.out.println(ois.readObject());
            System.out.println(ois.readInt());
            ois.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}