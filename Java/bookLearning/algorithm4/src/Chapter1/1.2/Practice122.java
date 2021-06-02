import edu.princeton.cs.algs4.Interval1D;
import edu.princeton.cs.algs4.StdDraw;

import java.util.Random;

public class Practice122 {
    public static void main(String[] args){
        int N = 10;
        Random random = new Random();
        Interval1D[] a = new Interval1D[N];
        for(int i = 0; i < N; i++){
            double x = random.nextDouble();
            double y = random.nextDouble();
            if(x >y){
                double temp = x;
                x = y;
                y = temp;
            }
            a[i] = new Interval1D(x,y);
        }
        for(int i = 0 ; i < N; i ++){
            for(int j = i + 1; j < N ; j++){
                if(a[i].intersects(a[j]))
                    System.out.println(a[i] + " " + a[j]);
            }
        }
    }
}
