import java.util.Scanner;

public class PalinNum {
    public static void main(String args[]) {
        System.out.println("input a 3-digit number:");
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        while (num / 100 == 0 || num / 100 >= 10) {
            System.out.println("input unquanlified! input again");
            num = input.nextInt();
        }
        int left = num / 100;
        int right = num % 10;
        if (left == right)
            System.out.println(num + " is a palindrome.");
        else
            System.out.println(num + " is not a palindrome");
    }
}
