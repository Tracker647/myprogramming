import edu.princeton.cs.algs4.Point2D;

import java.util.Random;

public class Practice121 {
    public static void main(String[] args) {
        int N = 100;
        Random random = new Random();
        Point2D[] points = new Point2D[N];
        for(int i = 0; i < points.length; i++){
            double x = random.nextDouble();
            double y = random.nextDouble();
            points[i] = new Point2D(x,y);
            points[i].draw();
        }
        double min;
        double distance;
        min = points[0].distanceTo(points[1]);
        for(int i = 0; i < points.length; i++){
            for(int j = i+1; j < points.length; j++)
            {
                distance = points[i].distanceTo(points[j]);
                if(random.nextDouble() > 0.99)
                    points[i].drawTo(points[j]);
                if(min > distance)
                {
                    min = distance;
                }
            }
        }
        System.out.println("minimum distance: " + min);
    }
}
