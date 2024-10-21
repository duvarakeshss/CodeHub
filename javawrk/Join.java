import java.io.*;
import java.util.Scanner;

public class Join {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String f1 = input.nextLine();
        String f2 = input.nextLine();
        String f3 = input.nextLine();
        
        try{
            
            File f  = new File(f3);
            if(f.createNewFile()){
                System.out.println("file created "+ f.getName());
            }
            else{
                System.out.println("File Already exists");
            }
        }
        catch(IOException e){
            System.out.println("Error");
            e.printStackTrace();
        }
        
        try{
            BufferedReader file1 = new BufferedReader(new FileReader(f1));
            BufferedReader file2 = new BufferedReader(new FileReader(f2));
            BufferedWriter file3 = new BufferedWriter(new FileWriter(f3));

            String line;
            while((line = file1.readLine())!=null){
                file3.write(line);
                file3.newLine();
            }
            while ((line = file2.readLine()) != null) {
                file3.write(line);
                file3.newLine();
            }
            file1.close();
            file2.close();
            file3.close();
        }
        catch(IOException e){
            System.out.println("Error");
            e.printStackTrace();

        }
        input.close();
        System.out.println("Written Successfully");
        
    }

    
}
