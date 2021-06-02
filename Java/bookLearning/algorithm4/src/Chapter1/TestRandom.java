
import java.util.Random;

public class TestRandom {
    public static void main(String[] args) {
        Random rand = new Random();
        int max = 15,min = 2;
        double maxD = 15,minD = 2;
        // Math的random方法实际上就取自Random.nextDouble()
        for (int i = 0; i < 100; i++) {
            // System.out.println((int)( Math.random() * (max - min + 1) + min));
            // System.out.printf("%.2f\n",( Math.random() * (maxD - minD + 1) + minD));
            // System.out.println(rand.nextInt( max - min + 1) + min);
            System.out.printf("%.2f\n",rand.nextDouble()* (maxD - minD + 1) + minD);
        }

    }
}
