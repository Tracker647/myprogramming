package Chapter1;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

import java.io.InputStream;
import java.util.Scanner;

public class Average {
    public static void main(String[] args) {
        double sum = 0.0;
        int cnt =0;
        while(!StdIn.isEmpty()){
            double key = StdIn.readDouble();
            sum+= key;

            cnt++;
        }
        double avg = sum /cnt;
        StdOut.printf("Average is %.5f\n",avg);

    }
}
