import java.io.*;
import java.util.Scanner;

public class CheckAcc {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String file = input.nextLine();

        try{
            BufferedReader f = new BufferedReader(new FileReader(file));
            String line;
            int sum;
            int lastDigit;

            while ((line = f.readLine()) != null) {
                if(line.length() == 15 && line.matches("\\d+"));{
                    sum = 0 ;
                    for(int i = 0 ; i < 14 ; i++){
                        sum += Character.getNumericValue(line.charAt(i));
                    }
                    int rem = sum%10;
                    lastDigit = Character.getNumericValue(line.charAt(14));

                    if(rem == lastDigit){
                        System.out.println(line+" valid");
                    }

                }
                
            }
        }
        catch(IOException e){
            System.out.println("Error");
            e.printStackTrace();
        }
    }    
}
