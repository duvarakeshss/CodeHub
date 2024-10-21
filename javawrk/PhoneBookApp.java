import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class PhoneBookApp {
    // HashMap to store the contact name and phone number
    private HashMap<String, String> phoneBook;

    // Constructor to initialize the PhoneBook
    public PhoneBookApp() {
        phoneBook = new HashMap<>();
    }

    // Method to add a contact
    public void addContact(String name, String number) {
        phoneBook.put(name, number);
    }

    // Method to lookup a contact
    public String lookupContact(String name) {
        return phoneBook.getOrDefault(name, "Contact not found!");
    }

    // Method to list all contacts
    public String listContacts() {
        StringBuilder list = new StringBuilder();
        for (Map.Entry<String, String> entry : phoneBook.entrySet()) {
            list.append(entry.getKey()).append(": ").append(entry.getValue()).append("\n");
        }
        return list.toString();
    }

    // Method to edit a contact's phone number
    public boolean editContact(String name, String newNumber) {
        if (phoneBook.containsKey(name)) {
            phoneBook.put(name, newNumber);
            return true;
        } else {
            return false;
        }
    }

    // Method to sort and display contacts
    public String sortedContacts() {
        TreeMap<String, String> sorted = new TreeMap<>(phoneBook);
        StringBuilder sortedList = new StringBuilder();
        for (Map.Entry<String, String> entry : sorted.entrySet()) {
            sortedList.append(entry.getKey()).append(": ").append(entry.getValue()).append("\n");
        }
        return sortedList.toString();
    }

    // GUI Class
    public static void main(String[] args) {
        PhoneBookApp phoneBook = new PhoneBookApp();

        // Create JFrame
        JFrame frame = new JFrame("PhoneBook Application");
        frame.setSize(400, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new FlowLayout());

        // Create components
        JTextField nameField = new JTextField(15);
        JTextField numberField = new JTextField(15);
        JTextArea displayArea = new JTextArea(10, 30);
        displayArea.setEditable(false);

        JButton addButton = new JButton("Add Contact");
        JButton lookupButton = new JButton("Lookup Contact");
        JButton listButton = new JButton("List Contacts");
        JButton editButton = new JButton("Edit Contact");
        JButton sortButton = new JButton("Sort Contacts");

        // Add components to the frame
        frame.add(new JLabel("Name:"));
        frame.add(nameField);
        frame.add(new JLabel("Phone:"));
        frame.add(numberField);
        frame.add(addButton);
        frame.add(lookupButton);
        frame.add(listButton);
        frame.add(editButton);
        frame.add(sortButton);
        frame.add(new JScrollPane(displayArea));

        // Add button listeners
        addButton.addActionListener(e -> {
            String name = nameField.getText();
            String number = numberField.getText();
            if (!name.isEmpty() && !number.isEmpty()) {
                phoneBook.addContact(name, number);
                displayArea.setText("Contact added: " + name);
            } else {
                displayArea.setText("Please enter a valid name and phone number.");
            }
        });

        lookupButton.addActionListener(e -> {
            String name = nameField.getText();
            if (!name.isEmpty()) {
                String result = phoneBook.lookupContact(name);
                displayArea.setText(result);
            } else {
                displayArea.setText("Please enter a contact name to lookup.");
            }
        });

        listButton.addActionListener(e -> {
            String contacts = phoneBook.listContacts();
            displayArea.setText(contacts.isEmpty() ? "No contacts found." : contacts);
        });

        editButton.addActionListener(e -> {
            String name = nameField.getText();
            String newNumber = numberField.getText();
            if (!name.isEmpty() && !newNumber.isEmpty()) {
                if (phoneBook.editContact(name, newNumber)) {
                    displayArea.setText("Contact updated: " + name);
                } else {
                    displayArea.setText("Contact not found!");
                }
            } else {
                displayArea.setText("Please enter a valid name and phone number.");
            }
        });

        sortButton.addActionListener(e -> {
            String sortedContacts = phoneBook.sortedContacts();
            displayArea.setText(sortedContacts.isEmpty() ? "No contacts found." : sortedContacts);
        });

        // Show the frame
        frame.setVisible(true);
    }
}

