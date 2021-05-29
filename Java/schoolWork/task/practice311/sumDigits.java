import java.util.Scanner;

public class sumDigits {//6.2
    public static void main(String arg[]) {
        int sum = 0, n = -1;
        System.out.println("Enter a number:");
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        int rem;
        while (n != 0) {
            rem = n % 10;
            sum += rem;
            n = n / 10;
        }
        System.out.println("The sum of the digits is " + sum);

    }
}
