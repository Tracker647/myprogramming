import java.util.Scanner;   //4.4

public class Hexagon {
    public static void main(String args[]) {
        System.out.println("Enter the side:");
        Scanner input = new Scanner(System.in);
        double s = input.nextDouble();
        double area = (6 * Math.pow(s, 2)) / (4 * Math.tan(Math.PI / 6));
        System.out.printf("The area of hexagon is %.2f", area);
    }
}
