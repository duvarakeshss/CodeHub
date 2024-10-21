import java.io.File;
import java.util.Scanner;

public class ReadFile {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the File Name : ");
        String fileName = input.next();
        File file = new File(fileName);

        if(file.exists()){
            System.out.println("File exists");

            if(file.isDirectory()){
                System.out.println("It is Directory");
            }
            else if(file.isFile()){
                System.out.println("It is file");
            }

            else{
                System.out.println("Unkown Type");
            }

            System.out.print("Length of the file : "+file.length());
        }

        input.close();
    }
    
}
