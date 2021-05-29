import java.util.Scanner;

public class feet2meter {
    public static void main(String args[]) {
        double feet;
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a value for feet:");
        feet = input.nextDouble();
        double meter = feet * 0.305;
        System.out.printf("%.1f feet is %.4f meters", feet, meter);

    }
}
