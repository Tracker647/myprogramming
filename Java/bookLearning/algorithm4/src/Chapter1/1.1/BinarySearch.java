
package Chapter1;
import java.util.Arrays;
import java.util.Scanner;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class BinarySearch {

    public static int rank(int key, int[] a) {
        //数组必须有序
        int lo = 0;
        int hi = a.length - 1;
        while (lo<=hi) {
            int mid = (lo + hi) / 2;
            if (key < a[mid]) {
                hi = mid - 1;
            } else if (key > a[mid]) {
                lo = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] whitelist =  StdIn.readAllInts();
        Arrays.sort(whitelist);
        System.out.println("Print args[0]:");
        for(int i=0; i< whitelist.length; i++)
            System.out.print(whitelist[i] + " ");
        while (!StdIn.isEmpty()) {
            int key = StdIn.readInt();
            if (rank(key, whitelist) < 0) {
                StdOut.println(key);
            }
        }
    }

}
