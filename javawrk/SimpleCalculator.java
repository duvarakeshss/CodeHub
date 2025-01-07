import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SimpleCalculator {
    public static void main(String[] args) {
        // Create the JFrame (window)
        JFrame frame = new JFrame("Simple Calculator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);
        frame.setLayout(new GridLayout(5, 2, 10, 10));

        // Create labels and text fields for number input
        JLabel label1 = new JLabel("Enter first number:");
        JTextField textField1 = new JTextField();
        JLabel label2 = new JLabel("Enter second number:");
        JTextField textField2 = new JTextField();

        // Create radio buttons for operation selection
        JRadioButton addButton = new JRadioButton("Addition");
        JRadioButton subButton = new JRadioButton("Subtraction");

        // Group the radio buttons so that only one can be selected at a time
        ButtonGroup operationGroup = new ButtonGroup();
        operationGroup.add(addButton);
        operationGroup.add(subButton);

        // Create a button for calculation
        JButton calculateButton = new JButton("Calculate");

        // Create a label to display the result
        JLabel resultLabel = new JLabel("Result: ");

        // Add action listener to the calculate button
        calculateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    // Get the two numbers from the text fields
                    double num1 = Double.parseDouble(textField1.getText());
                    double num2 = Double.parseDouble(textField2.getText());
                    double result = 0;

                    // Perform the selected operation
                    if (addButton.isSelected()) {
                        result = num1 + num2;
                    } else if (subButton.isSelected()) {
                        result = num1 - num2;
                    } else {
                        resultLabel.setText("Please select an operation");
                        return;
                    }

                    // Display the result
                    resultLabel.setText("Result: " + result);
                } catch (NumberFormatException ex) {
                    // If the input is not a valid number, show an error message
                    resultLabel.setText("Invalid input! Please enter valid numbers.");
                }
            }
        });

        // Add components to the frame
        frame.add(label1);
        frame.add(textField1);
        frame.add(label2);
        frame.add(textField2);
        frame.add(addButton);
        frame.add(subButton);
        frame.add(calculateButton);
        frame.add(resultLabel);

        // Make the frame visible
        frame.setVisible(true);
    }
}