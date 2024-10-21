import java.io.*;
import java.util.Scanner;

class Person implements Serializable{
    String Name;
    String Age;
    Person(String n , String a){
        this.Name = n;
        this.Age = a;
    }
    public String toString(){
        return this.Name+" "+this.Age;
    }
}

public class Objwrite {

    public static void main(String[] args) {
        Person p = new Person("Hello", "20");

        try {
            // Serialize the object
            ObjectOutputStream s = new ObjectOutputStream(new FileOutputStream("go.txt"));
            s.writeObject(p);
            s.close();
            System.out.println("Object has been serialized to go.txt");

            // Deserialize the object
            ObjectInputStream c = new ObjectInputStream(new FileInputStream("go.txt"));
            Person p1 = (Person) c.readObject();
            System.out.println("Deserialized Object: " + p1.toString());
            c.close();
        }
        catch(IOException e){
            System.out.println("error");
        }
        catch (ClassNotFoundException e) {
            System.out.println("Class not found: " + e.getMessage());
        }
    }
}