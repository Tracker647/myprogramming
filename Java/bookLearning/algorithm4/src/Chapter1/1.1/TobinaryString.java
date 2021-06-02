package Chapter1;

import java.util.Scanner;

public class TobinaryString {
    public static void main(String[] args) {
//        Scanner input = new Scanner(System.in);
//        System.out.println("input the integer");
//        int N = input.nextInt();
//        System.out.println(toBinaryString(N));
        System.out.println((char)('a'+4));
    }
    public static StringBuilder toBinaryString(int n){
        StringBuilder s = new StringBuilder();
        for(int i = n ; i > 0; i /= 2){
            s = s.append(i%2);
        }
        return s.reverse();
    }
}
