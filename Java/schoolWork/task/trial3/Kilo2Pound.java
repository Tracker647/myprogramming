public class Kilo2Pound { // 5.5
    public static void main(String[] args) {
        int kilo1, pound2;
        double kilo2, pound1;
        System.out.println("Kilograms   Pounds  |   Pounds  Kilograms");
   
        for (int i = 1; i < 100; i++) {
            kilo1 = i * 2 - 1;
            pound1 = i * 2.2;
            pound2 = 5 * i + 15;
            kilo2 = pound2 / 2.2;
            System.out.printf( "      %3d    %5.1f  |  %3d          %5.2f\n", kilo1, pound1, pound2, kilo2);
        }
    }
}
