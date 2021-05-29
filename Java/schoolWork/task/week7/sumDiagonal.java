import java.util.Scanner;

public class sumDiagonal {
    public static void main(String args[]) {
        double[][] mar = new double[4][4];
        double sum;
        System.out.println("Enter a 4-by-4 matrix row by row:");
        Scanner input = new Scanner(System.in);
        int i, j;
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
                mar[i][j] = input.nextDouble();
        sum = sumMajorDiagonal(mar);
        System.out.println("Sum of the elements in the major diagonal " + sum);
    }

    public static double sumMajorDiagonal(double[][] m) {
        int i, k = 0;
        double sum = 0;
        for (i = 0; i < 4; i++)
            sum += m[i][k++];

        return sum;
    }
}
