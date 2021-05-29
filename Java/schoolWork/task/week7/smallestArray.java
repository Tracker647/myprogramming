import java.util.Scanner;

public class smallestArray {
    public static void main(String args[]) {
        int i;
        double[] arr = new double[10];
        System.out.println("Enter ten numbers:");
        Scanner input = new Scanner(System.in);
        for (i = 0; i < 10; i++)
            arr[i] = input.nextDouble();
        double min = arr[0];
        for (i = 1; i < arr.length; i++) {
            if (min > arr[i])
                min = arr[i];
        }
        System.out.println("The minimum number is " + min);
    }
}