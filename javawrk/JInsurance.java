import javax.swing.*;
import java.awt.*;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

public class JInsurance implements ItemListener {
    // Declare checkboxes and text field
    private JCheckBox hmoCheckBox, ppoCheckBox, dentalCheckBox, visionCheckBox;
    private JTextField resultField;
    private ButtonGroup insuranceTypeGroup;

    // Prices for the insurance options
    private final int HMO_PRICE = 200;
    private final int PPO_PRICE = 600;
    private final int DENTAL_PRICE = 75;
    private final int VISION_PRICE = 20;

    // Constructor to set up the components
    public JInsurance() {
        // Create a JFrame instance
        JFrame frame = new JFrame("Insurance Options");
        frame.setSize(400, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(6, 1));

        // Create checkboxes for insurance options
        hmoCheckBox = new JCheckBox("HMO - $200/month");
        ppoCheckBox = new JCheckBox("PPO - $600/month");
        dentalCheckBox = new JCheckBox("Dental - $75/month");
        visionCheckBox = new JCheckBox("Vision - $20/month");

        // Group the HMO and PPO checkboxes to allow only one selection
        insuranceTypeGroup = new ButtonGroup();
        insuranceTypeGroup.add(hmoCheckBox);
        insuranceTypeGroup.add(ppoCheckBox);

        // Create a text field to display the selected options and prices
        resultField = new JTextField();
        resultField.setEditable(false);

        // Add item listeners to the checkboxes
        hmoCheckBox.addItemListener(this);
        ppoCheckBox.addItemListener(this);
        dentalCheckBox.addItemListener(this);
        visionCheckBox.addItemListener(this);

        // Add components to the frame
        frame.add(hmoCheckBox);
        frame.add(ppoCheckBox);
        frame.add(dentalCheckBox);
        frame.add(visionCheckBox);
        frame.add(resultField);

        // Make the frame visible
        frame.setVisible(true);
    }

    @Override
    public void itemStateChanged(ItemEvent e) {
        // Calculate total cost based on selected options
        int totalCost = 0;
        StringBuilder result = new StringBuilder();

        if (hmoCheckBox.isSelected()) {
            totalCost += HMO_PRICE;
            result.append("HMO: $200 ");
        } else if (ppoCheckBox.isSelected()) {
            totalCost += PPO_PRICE;
            result.append("PPO: $600 ");
        }

        if (dentalCheckBox.isSelected()) {
            totalCost += DENTAL_PRICE;
            result.append("Dental: $75 ");
        }

        if (visionCheckBox.isSelected()) {
            totalCost += VISION_PRICE;
            result.append("Vision: $20 ");
        }

        // Update the result field or clear it if nothing is selected
        if (totalCost > 0) {
            resultField.setText(result.toString() + " | Total: $" + totalCost);
        } else {
            resultField.setText("");
        }
    }

    public static void main(String[] args) {
        // Run the application by creating an instance of JInsurance
        new JInsurance();
    }
}
