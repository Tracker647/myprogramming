import edu.princeton.cs.algs4.Interval1D;
import edu.princeton.cs.algs4.Interval2D;
import edu.princeton.cs.algs4.StdRandom;

import java.util.Random;

public class Practice123 {
    public static void main(String[] args) {
        int N = 30;
        double min = 0.0, max = 1.0;
        Random random = new Random();
        Interval1D x, y;
        Interval2D[] box = new Interval2D[N];
        double temp;
        for (int i = 0; i < N; i++) {
            double xlo = random.nextDouble() * (max - min + 1) + min;
            double xhi = random.nextDouble() * (max - min + 1) + min;
            double ylo = random.nextDouble() * (max - min + 1) + min;
            double yhi = random.nextDouble() * (max - min + 1) + min;
            if (xlo > xhi) {
                temp = xlo;
                xlo = xhi;
                xhi = temp;
            }
            if (ylo > yhi) {
                temp = ylo;
                ylo = yhi;
                yhi = temp;
            }
            x = new Interval1D(xlo, xhi);
            y = new Interval1D(ylo, yhi);
            box[i] = new Interval2D(x, y);
            box[i].draw();
        }
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (box[i].intersects(box[j])) {
                    count++;
                }
            }

        }
        System.out.println(count);
    }
}


