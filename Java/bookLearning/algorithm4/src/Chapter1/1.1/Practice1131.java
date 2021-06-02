package Chapter1;

import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdRandom;

import java.util.Random;

public class Practice1131 {
    private static class Point{
        private double x;
        private double y;
        public Point(double x,double y){
            this.x = x;
            this.y = y;
        }
    }
    public static void main(String[] args) {
        int N = 10;
        double p = 0.5;
        double x0 = 0.5,y0 = 0.5, r = 0.3;
        StdDraw.circle(x0,y0,r);
        StdDraw.setPenRadius(0.05);
        Point[] points = new Point[N];
        for(int i = 0; i < N ; i ++){
//            怎么推导出这个公式?
            double angle = i * 2 * Math.PI/N;
            double x = x0 + r*Math.sin(angle);
            double y = y0 + r*Math.cos(angle);
            points[i] = new Point(x,y);
            System.out.printf("x: %f y:%f angle:%f\n",x,y,angle);
            StdDraw.point(points[i].x,points[i].y);
        }
        StdDraw.setPenRadius(0.005);
        for(int i = 0; i < N; i ++){
            for(int j = i+1; j < N ; j++){
                if(bernoulli(p))
                    StdDraw.line(points[i].x,points[i].y,points[j].x,points[j].y);
            }
        }
    }
    public static boolean bernoulli(double p){
        Random random = new Random();
        if(p< 0 || p > 1.0)
            throw new IllegalArgumentException("probablity p must between 0.0 and 1.0: "+ p);
        return random.nextDouble() < p;
    }
}
