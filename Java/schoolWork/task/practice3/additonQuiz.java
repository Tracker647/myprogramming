
import java.util.Scanner;
public class additonQuiz {  
    public static void main(String args[]) {
        int num1 = (int) (Math.random() * 100);
        int num2 = (int) (Math.random() * 100);
        System.out.println("What is " + num1 + " + " + num2 + "?");
        Scanner input = new Scanner(System.in);
        int answer = input.nextInt();
        if (num1 + num2 == answer) {
            System.out.println("Your answer correct.");
        } else {
            System.out.println("Wrong," + num1 + " + " + num2 + " Shoule be" + (num1 + num2) + ".");
        }
    }
}
