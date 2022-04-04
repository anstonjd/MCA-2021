import java.io.*;

class bufferedFile {
    public static void main(String[] args) {
        String str = "This is a string ";
        char ch[] = new char[str.length()];
        ch = str.toCharArray();
        FileWriter fw = null;
        FileReader fr = null;
        try {
            fw = new FileWriter("text1.txt");
            BufferedWriter bw = new BufferedWriter(fw);
            bw.write(ch);
            bw.close();
            fr = new FileReader("text1.txt");
            BufferedReader br = new BufferedReader(fr);
            int i;
            while ((i = br.read()) != -1) {
                System.out.print((char) i);
            }
            br.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
