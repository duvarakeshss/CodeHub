import java.io.*;
import java.util.*;
public class Trac {

    public void perform(String master , String transaction){
        Map<String ,Double> mrec = new HashMap<>();
        Map<String ,Double> trec = new HashMap<>();

        try{
            BufferedReader file1 = new BufferedReader(new FileReader(master));
            BufferedReader file2 = new BufferedReader(new FileReader(transaction));

            String line;
            while ((line = file1.readLine())!=null) {
                String[] p = line.split(" ");
                String acc = p[0].trim();
                Double amt = Double.parseDouble(p[1].trim());

                mrec.put(acc,amt);
                
            }
            while ((line = file2.readLine())!=null) {
                String[] p = line.split(" ");
                String acc = p[0].trim();
                Double amt = Double.parseDouble(p[1].trim());

                trec.put(acc,amt);
                
            }
            String file3 = "newmast.txt";
            String file4 = "log.txt";
            File n1 = new File(file3);
            File n2 = new File(file4);
            n1.createNewFile();
            n2.createNewFile();

            BufferedWriter f = new BufferedWriter(new FileWriter(file3));
            BufferedWriter g = new BufferedWriter(new FileWriter(file4));

            for(Map.Entry<String , Double> mlist : mrec.entrySet()){
                String acc = mlist.getKey();
                Double amt = mlist.getValue();

                if(trec.containsKey(acc)){
                    amt += trec.get(acc);
                }
                f.write(acc +" "+amt);
                f.newLine();

            }
            f.close();

            for(Map.Entry<String,Double> tlist : trec.entrySet()){
                if(!mrec.containsKey(tlist.getKey())){
                    g.write(tlist.getKey()+" "+tlist.getValue());
                    g.newLine();
                }
            }
            g.close();
        }
        catch(IOException e){
            System.out.println("Error");
            e.printStackTrace();
        }


    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String M = input.nextLine();
        String T = input.nextLine();
        Trac obj = new Trac();
        obj.perform(M, T);
    }
    
}
