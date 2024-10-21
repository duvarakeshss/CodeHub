import javax.swing.*;
import java.awt.*;

public class ShapeDrawer extends JPanel {

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;

        // Set anti-aliasing for smooth shapes
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        // Draw a filled rectangle
        g2d.setColor(Color.BLUE);
        g2d.fillRect(50, 50, 100, 60);

        // Draw a rectangle outline
        g2d.setColor(Color.BLACK);
        g2d.drawRect(50, 50, 100, 60);

        // Draw a filled oval
        g2d.setColor(Color.RED);
        g2d.fillOval(200, 50, 100, 60);

        // Draw an oval outline
        g2d.setColor(Color.BLACK);
        g2d.drawOval(200, 50, 100, 60);

        // Draw a filled polygon (triangle)
        int[] xPoints = {350, 400, 300};
        int[] yPoints = {50, 100, 100};
        g2d.setColor(Color.GREEN);
        g2d.fillPolygon(xPoints, yPoints, 3);

        // Draw a polygon outline (triangle)
        g2d.setColor(Color.BLACK);
        g2d.drawPolygon(xPoints, yPoints, 3);

        // Draw a filled arc
        g2d.setColor(Color.ORANGE);
        g2d.fillArc(50, 150, 100, 100, 0, 120);

        // Draw an arc outline
        g2d.setColor(Color.BLACK);
        g2d.drawArc(50, 150, 100, 100, 0, 120);

        // Draw a line
        g2d.setColor(Color.MAGENTA);
        g2d.drawLine(200, 200, 300, 300);
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Shape Drawer");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 400);
        frame.add(new ShapeDrawer());
        frame.setLocationRelativeTo(null); // Center the frame
        frame.setVisible(true);
    }
}
