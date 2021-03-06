import java.util.Scanner;

public class isPrimee {
    public static void main(String[] args) {
        System.out.println("The prime numbers lesser than 10000 are\n");
        printPrimeNumbers(10000);
    }

    public static void printPrimeNumbers(int maxNumber) {
        final int NUMBER_OF_PRIMES_PER_LINE = 10;
        int count = 0;
        int number = 2;
        while (number <= maxNumber) {
            if (isPrime(number)) {
                count++;
                if (count % NUMBER_OF_PRIMES_PER_LINE == 0) {
                    System.out.printf("%5d \n", number);
                } else {
                    System.out.printf("%5d ", number);
                }
            }
            number++;
        }
    }

    public static boolean isPrime(int number) {
        for (int divisor = 2; divisor <= number / 2; divisor++) {
            if (number % divisor == 0)
                return false;
        }
        return true;
    }
}
