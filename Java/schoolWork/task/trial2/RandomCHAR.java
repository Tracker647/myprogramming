public class RandomCHAR {       //4.16
    public static void main(String args[]) {
        int x1 = 65, x2 = 90;
        double f = Math.random() / Math.nextDown(1.0);
        double x = x1 * (1.0 - f) + x2 * f;
        System.out.println((char) x);
    }
}
