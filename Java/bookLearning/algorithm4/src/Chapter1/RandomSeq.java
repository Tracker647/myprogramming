package Chapter1;


import java.util.Random;

public class RandomSeq {
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        double lo = Double.parseDouble(args[1]);
        double hi = Double.parseDouble(args[2]);
        Random random = new Random();
        for(int i = 0; i < N; i++){
            double x = random.nextDouble() * (hi - lo) + lo;
            System.out.printf("%.2f\n",x);
        }
    }
}
