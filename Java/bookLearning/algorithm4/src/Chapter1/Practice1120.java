package Chapter1;

import java.util.Scanner;

public class Practice1120 {
    public static void main(String[] args) {
        System.out.println("input N:");
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        System.out.println(ln(N));
    }

    public static double ln(int n){
        if(n == 1) return 0;
        else return ln(n - 1) + Math.log(n);
    }
}
