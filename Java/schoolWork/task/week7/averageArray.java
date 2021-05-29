import java.util.Scanner;

public class averageArray {
    public static void main(String args[]) {
        double[] arr = new double[10];
        int i;
        System.out.println("Enter 10 number");
        Scanner input = new Scanner(System.in);
        for (i = 0; i < 10; i++) {
            arr[i] = input.nextDouble();
        }
        double avg = average(arr);
        System.out.println("the average is: " + avg);
    }

    public static int average(int[] array) {
        int sum = 0;
        for (int i = 0; i < array.length; i++)
            sum += array[i];
        return sum / array.length;
    }

    public static double average(double[] array) {
        double sum = 0;
        for (int i = 0; i < array.length; i++)

        sum += array[i];
        return sum / array.length;
    }
}
