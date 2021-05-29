public class DisvisibleBut30 { // 5.11
    public static void main(String[] args) {
        int i, count = 0;
        for (i = 100; i <= 200; i++) {
            if ((i % 5 == 0 && i % 6 != 0) || (i % 5 != 0 && i % 6 == 0)) {
                System.out.printf("%d ",i);
                count++;
            }
            if(count == 10){
                System.out.printf("\n");
                count = 0;
            }
        }

    }
}
