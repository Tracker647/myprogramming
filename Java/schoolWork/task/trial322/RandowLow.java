import java.util.Random;

public class RandowLow {
    public static void main(String args[]) {
        int x1 = 97, x2 = 122;
        double f = Math.random() / Math.nextDown(1.0);
        double x = x1 * (1.0 - f) + x2 * f;
        System.out.println((char)x);
    }

}
