package Chapter1;

import edu.princeton.cs.algs4.*;


public class TestStdDraw {
    public static void main(String[] args) {
        int N = 100;
//        绘制函数
//        StdDraw.setXscale(0,N);
//        StdDraw.setYscale(0,N*N);
//        StdDraw.setPenRadius(0.01);
//        for(int i = 1;i <= N; i++){
//            StdDraw.point(i,i*i);
//
//        }
        N = 50;
        double[] a = new double[N];
        for(int i = 0; i<N; i++)
            a[i] = Math.random();
        for(int i =0; i<N; i++){
            double x = 1.0*i/N;
            double y = a[i]/2.0;
            double rw = 0.5/N;
            double rh = a[i]/2.0;
            StdDraw.filledRectangle(x,y,rw,rh);
        }
    }
}
