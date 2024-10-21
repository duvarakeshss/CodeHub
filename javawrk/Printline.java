import java.io.*;
import java.util.Scanner;
public class Printline {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String file = input.next();
        // try{
        //     BufferedReader file1 = new BufferedReader(new FileReader(file));
        //     String line;
        //     int i = 1;
        //     while ((line = file1.readLine()) != null) {
        //         System.out.println(i + ". "+ line);
        //         i =i+1 ;
        //     }
        //     file1.close();
        //     input.close();
        // }
        // catch(IOException e){
        //     System.out.println("Error");
        //     e.printStackTrace();
        // }
        try{
            BufferedReader file1 = new BufferedReader(new FileReader(file));
            String line;
            int countLines = 0,count_blank = 0,semi = 0;
            while ((line = file1.readLine()) != null) {
                countLines++;
                if(line.trim().isEmpty()){
                    count_blank++;
                }
                if(line.trim().endsWith(";")){
                    semi++;
                }
                
            }
            file1.close();
            System.out.println("Total line : "+countLines);
            System.out.println("Blank Lines : "+count_blank);
            System.out.println("Total Semicolons : "+semi);
        }
        catch(IOException e){
            System.out.println("Error");
            e.printStackTrace();
        }
        input.close();

    }
    
}
