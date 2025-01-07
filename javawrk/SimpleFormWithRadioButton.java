import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SimpleFormWithRadioButton {
    public static void main(String[] args) {
        // Create the JFrame (window) for the form
        JFrame frame = new JFrame("User Information Form");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);
        frame.setLayout(new GridLayout(6, 2)); // 6 rows, 2 columns

        // Create labels and text fields for the form
        JLabel nameLabel = new JLabel("Name:");
        JTextField nameField = new JTextField();
        
        JLabel emailLabel = new JLabel("Email:");
        JTextField emailField = new JTextField();
        
        JLabel ageLabel = new JLabel("Age:");
        JTextField ageField = new JTextField();
        
        // Create radio buttons for gender selection
        JLabel genderLabel = new JLabel("Gender:");
        JRadioButton maleButton = new JRadioButton("Male");
        JRadioButton femaleButton = new JRadioButton("Female");
        JRadioButton otherButton = new JRadioButton("Other");

        // Group the radio buttons so that only one can be selected at a time
        ButtonGroup genderGroup = new ButtonGroup();
        genderGroup.add(maleButton);
        genderGroup.add(femaleButton);
        genderGroup.add(otherButton);

        // Create a submit button
        JButton submitButton = new JButton("Submit");

        // Create a label to display the result after submitting the form
        JLabel resultLabel = new JLabel(" ");

        // Add action listener to the submit button
        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Get the entered values from the form
                String name = nameField.getText();
                String email = emailField.getText();
                String age = ageField.getText();
                
                // Get the selected gender
                String gender = "";
                if (maleButton.isSelected()) {
                    gender = "Male";
                } else if (femaleButton.isSelected()) {
                    gender = "Female";
                } else if (otherButton.isSelected()) {
                    gender = "Other";
                }

                // Display the result in the result label
                resultLabel.setText("<html>Name: " + name + "<br>Email: " + email + "<br>Age: " + age + "<br>Gender: " + gender + "</html>");
            }
        });

        // Add components to the frame
        frame.add(nameLabel);
        frame.add(nameField);
        frame.add(emailLabel);
        frame.add(emailField);
        frame.add(ageLabel);
        frame.add(ageField);
        frame.add(genderLabel);
        
        // Add radio buttons horizontally (1 row for all gender buttons)
        JPanel genderPanel = new JPanel();
        genderPanel.add(maleButton);
        genderPanel.add(femaleButton);
        genderPanel.add(otherButton);
        frame.add(genderPanel);
        
        frame.add(submitButton);
        frame.add(resultLabel);

        // Make the frame visible
        frame.setVisible(true);
    }
}
