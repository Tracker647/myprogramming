package Chapter1;

import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class VisualAccumulator {
    private double total;
    private int N;
    public VisualAccumulator(int trials,double max){
        StdDraw.setXscale(0,trials);
        StdDraw.setYscale(0,max);
        StdDraw.setPenRadius(.005);
    }
    public void addDataValue(double val){
        N++;
        total +=val;
        StdDraw.setPenColor(StdDraw.DARK_GRAY);
        StdDraw.point(N,val);
        StdDraw.setPenColor(StdDraw.RED);
        StdDraw.point(N,total/N);
    }
    public static void main(String[] args) {
        int T = Integer.parseInt("5");
        VisualAccumulator a = new VisualAccumulator(T,1.0);
        for(int t = 0; t < T; t++){
            a.addDataValue(StdRandom.uniform());
        }
        StdOut.println(a);
    }
}
